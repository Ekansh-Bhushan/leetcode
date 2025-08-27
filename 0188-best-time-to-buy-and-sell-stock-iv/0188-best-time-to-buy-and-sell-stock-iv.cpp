class Solution {
    int n;
public:
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        if (n == 0 || k == 0) return 0;

        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

        for (int i = n-1; i >= 0; i--) {
            for (int transaction = 0; transaction < 2*k; transaction++) {
                if (transaction % 2 == 0) {
                    dp[i][transaction] = max(-prices[i] + dp[i+1][transaction+1],dp[i+1][transaction]);
                } else {
                    dp[i][transaction] = max(prices[i] + dp[i+1][transaction+1],dp[i+1][transaction]);
                }
            }
        }

        return dp[0][0];
    }
};
