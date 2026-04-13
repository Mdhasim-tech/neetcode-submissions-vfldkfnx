class Solution {
    int rows;
    int cols;
public:
    int func(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp){
        if(i==rows)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int down=triangle[i][j]+func(i+1,j,triangle,dp);
        int right=1e9;
        if(j<triangle[i].size()){
            right=triangle[i][j]+func(i+1,j+1,triangle,dp);
        }
        return dp[i][j]=min(down,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        rows=triangle.size();
        cols=triangle[rows-1].size();
        vector<vector<int>>dp(rows+1,vector<int>(cols,0));
        for(int i=rows-1;i>=0;i--){
            for(int j=cols-1;j>=0;j--){
                int down=triangle[i][j]+dp[i+1][j];
                int right=1e9;
                if(j<triangle[i].size()){
                    right=triangle[i][j]+dp[i+1][j+1];
                }
            dp[i][j]=min(down,right);
            }
        }
        return dp[0][0];
    }
};