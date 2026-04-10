class Solution {
public:
    int func(int ind,int end,vector<int>&dp){
        if(ind==end)return 1;
        if(dp[ind]!=-1)return dp[ind];
        int take1=func(ind+1,end,dp);
        int take2=0;
        if(ind+2<=end){
            take2=func(ind+2,end,dp);
        }
        return dp[ind]=take1+take2;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return func(0,n,dp);
    }
};
