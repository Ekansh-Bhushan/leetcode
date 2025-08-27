class Solution {
    int n;
public:
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,0));

        dp[n-1][0] = 0;
        dp[n-1][1] = 0;

        for(int i = n-1 ; i >= 0 ; i--) {
            for(int buy = 0; buy < 2 ; buy++) {
                if(buy) {
                    dp[i][buy] = max(-prices[i] + dp[i+1][!buy], dp[i+1][buy]);
                } else {
                     dp[i][buy] = max(prices[i] + dp[i+1][!buy] - fee, dp[i+1][buy]);
                }
            }
        }
        return dp[0][1];
    }
};