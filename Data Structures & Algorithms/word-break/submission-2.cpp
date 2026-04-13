class Solution {
    unordered_set<string>mpp;
public:
    bool func(int ind,string& s,vector<string>& wordDict,vector<int>&dp){
        if(ind==s.size())return true;
        if(dp[ind]!=-1)return dp[ind];
        string str="";
        for(int i=ind;i<s.size();i++){
            str+=s[i];
            if(mpp.find(str)!=mpp.end()){
                if(func(i+1,s,wordDict,dp)==true){
                    return dp[ind]=true;
                }
            }
        }
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n,-1);
        for(auto it:wordDict){
            mpp.insert(it);
        }
        return func(0,s,wordDict,dp);
    }
};
