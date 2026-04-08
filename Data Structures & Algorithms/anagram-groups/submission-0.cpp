class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        vector<vector<string>>ans;
        for(int i=0;i<strs.size();i++){
            string w=strs[i];
            sort(w.begin(),w.end());
            if(mpp.count(w)){
                mpp[w].push_back(strs[i]);
            }else{
                mpp[w].push_back(strs[i]);
            }
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
