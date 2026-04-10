class Solution {
public:
    int func(int ind,int end,vector<int>&cost,vector<int>&dp){
        if(ind>=end)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int take1=cost[ind]+func(ind+1,end,cost,dp);
       
        
        int take2=cost[ind]+func(ind+2,end,cost,dp);
        
        return dp[ind]=min(take1,take2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(func(0,n,cost,dp),func(1,n,cost,dp));
    }
};
