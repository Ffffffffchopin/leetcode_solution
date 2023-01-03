class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ret=0;
        for (int i=0;i<strs[0].size();i++){
            char former=0;
            for(string s:strs){
                if (s[i]<former){
                    ret++;
                    break;
                }
                former=s[i];
            }
        }
        return ret;
    }
};