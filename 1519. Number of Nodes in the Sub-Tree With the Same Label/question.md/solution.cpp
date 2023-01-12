class Solution {
public:

    void dfs(vector<vector<int> >& adj,int node,int prev,vector<int>& ret,string& labels,vector<int>& map){
        int i=labels[node]-'a';
        
       int prev_count=map[i];
       map[i]++;
        for(auto ele:adj[node]){
            if(ele!=prev){
                dfs(adj,ele,node,ret,labels,map);
            }
        }
        ret[node]=map[i]-prev_count;
        
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int> > adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> ret(n,0);
        vector<int> map(26,0);
        dfs(adj,0,0,ret,labels,map);
        return ret;
    }
};