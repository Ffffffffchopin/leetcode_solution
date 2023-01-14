class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> tree(26);
        for(int i=0;i<26;i++){
            tree[i]=i;
        }
        unordered_set<char> visited;
        for(int i=0;i<s1.size();i++){
            char a=s1[i]-'a';
            char b=s2[i]-'a';
            if(tree[a]==tree[b]){
                continue;
            }
            int min,max;
            if (tree[a]<=tree[b]){
                min=a;
                max=b;
            }
            else{
                min=b;
                max=a;
            }
           
            for(char c:visited){
                if((c==s1[i])||(c==s2[i])){
                    continue;
                }
                if(tree[c-'a']==tree[max]){
                    tree[c-'a']=tree[min];
                }
            }
             tree[max]=tree[min];
            visited.insert(s1[i]);
            visited.insert(s2[i]);
            
        }
        string ret="";
        for(char c:baseStr){
            char tmp=tree[c-'a']+97;
            ret+=tmp;
        }
        return ret;
    }
};