class Solution {
public:

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int> > adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int ret=dfs(adj,0,-1,hasApple);
        ret=ret*=2;
        return ret;
    }
    int dfs(vector<vector<int> > adj,int node,int prev,vector<bool>& hasApple){
        int tree=0;
        int subtree;
        for(auto ele:adj[node]){
            if(ele!=prev){
                subtree=dfs(adj,ele,node,hasApple);
                tree+=subtree;
            }
        }
        if((adj[node].size()==1)&&(node!=0)){
            tree+=hasApple[node];
        }
        else if(node!=0){
            if((hasApple[node])||(subtree!=0)){
                tree++;
            }
        }
        return tree;
    }
};