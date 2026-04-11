class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        int n = coins.size();
        int INF = 1e9;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, INF));

        // Base case
        for(int i = 0; i <= n; i++) {
            dp[i][target] = 0;
        }

        for(int i = n - 1; i >= 0; i--) {
            for(int amount = target - 1; amount >= 0; amount--) {

                int pick = INF;

                // ✅ SAFE CHECK (no overflow)
                if(coins[i] <= target - amount) {
                    pick = 1 + dp[i][amount + coins[i]];
                }

                int notpick = dp[i + 1][amount];

                dp[i][amount] = min(pick, notpick);
            }
        }

        int ans = dp[0][0];
        return (ans >= INF) ? -1 : ans;
    }
};