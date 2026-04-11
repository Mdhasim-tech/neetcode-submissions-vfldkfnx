class Solution {
public:
    int func(int ind,int base_ind,vector<int>&nums,vector<int>&dp){
        if(ind>=base_ind)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int rob=nums[ind]+func(ind+2,base_ind,nums,dp);
        int notrob=0+func(ind+1,base_ind,nums,dp);
        return dp[ind]=max(rob,notrob);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
       
        return max(func(0,n-1,nums,dp1),func(1,n,nums,dp2));
    }
};
