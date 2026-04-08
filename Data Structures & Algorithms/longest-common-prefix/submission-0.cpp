class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int m=INT_MAX;
        for(auto it:strs){
            m=min(m,(int)it.size());
        }
        string ans="";
        for(int i=0;i<m;i++){
            char ch=strs[0][i];
            for(int j=1;j<n;j++){
                if(strs[j][i]!=ch){
                    return ans;
                }
            }
            ans+=ch;
        }
        return ans;
    }
};