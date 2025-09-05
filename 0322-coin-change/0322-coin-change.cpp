class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0)
                dp[0][target] = target / coins[0];
        }

        for (int i = 1; i < n; i++) {
            for (int target = 0; target <= amount; target++) {
                int notPick = dp[i - 1][target];
                int pick = 1e9;
                if (target >= coins[i]) {
                    pick = 1 + dp[i][target - coins[i]];
                }
                dp[i][target] = min(pick, notPick);
            }
        }

        int ans = dp[n - 1][amount];
        return ans >= 1e9 ? -1 : ans;
    }
};
