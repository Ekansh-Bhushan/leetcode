class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        int n = coins.size();

        vector<int> prev(amount + 1, 1e9);
        vector<int> curr(amount + 1, 1e9);

        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0)
                prev[target] = target / coins[0];
        }

        for (int i = 1; i < n; i++) {
            for (int target = 0; target <= amount; target++) {
                int notPick = prev[target];
                int pick = 1e9;
                if (target >= coins[i]) {
                    pick = 1 + curr[target - coins[i]];
                }
                curr[target] = min(pick, notPick);
            }
            prev = curr;
        }

        int ans = prev[amount];
        return ans >= 1e9 ? -1 : ans;
    }
};
