class Solution {
public:
    int func(int ind,string& s,vector<int>&dp){
        if(ind==s.size())return 1;
        if(s[ind]=='0')return 0;
        if(dp[ind]!=-1)return dp[ind];
        int p1=0;
        if(s[ind]>='1' && s[ind]<='9'){
            p1=func(ind+1,s,dp);
        }
        int p2=0;
        if(ind+1<s.size()){
            string two=s.substr(ind,2);
            if(two>="10" && two<="26"){
                p2=func(ind+2,s,dp);
            }
        }
        return dp[ind]=p1+p2;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return func(0,s,dp);
    }
};
