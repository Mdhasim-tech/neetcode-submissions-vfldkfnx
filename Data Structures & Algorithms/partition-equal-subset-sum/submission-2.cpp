class Solution {
    int n;
public:
    bool func(int ind,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(ind==0)return target==0;
        if(dp[ind][target]!=-1)return dp[ind][target];
        bool notpick=func(ind-1,target,nums,dp);
        bool pick=false;
        if(nums[ind]<=target){
            pick=func(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target]=notpick||pick;
    }
    bool canPartition(vector<int>& nums) {
        n=nums.size();
        int total=0;
        for(auto it:nums)total+=it;
        if(total%2!=0)return false;
        int target=total/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return func(n-1,target,nums,dp);
    }
};
