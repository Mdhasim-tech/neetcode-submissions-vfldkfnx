class Solution {
public:
    int lower_bound(int x,vector<int>&days){
        int low=0;
        int high=days.size()-1;
        int ans=days.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(days[mid]>x){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    int func(int ind,vector<int>&days,vector<int>& costs,vector<int>&dp){
        if(ind==days.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int mini=INT_MAX;
        int valid_till=days[ind];
        //Find the next day to travel-lower bound of valid till
        int next_ind=lower_bound(valid_till,days);
        int path1=costs[0]+func(next_ind,days,costs,dp);

        valid_till=days[ind]+6;
        next_ind=lower_bound(valid_till,days);
        int path2=costs[1]+func(next_ind,days,costs,dp);

        valid_till=days[ind]+29;
        next_ind=lower_bound(valid_till,days);
        int path3=costs[2]+func(next_ind,days,costs,dp);

        mini=min({path1,path2,path3});
        return dp[ind]=mini;

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size(),-1);
        return func(0,days,costs,dp);
    }
};