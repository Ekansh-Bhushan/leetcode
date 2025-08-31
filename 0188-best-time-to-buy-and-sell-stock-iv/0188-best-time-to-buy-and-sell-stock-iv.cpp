class Solution {
    int n;
public:
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1,0)));

        for(int i = n-1 ; i>=0 ; i--) {
            for(int buy = 0; buy < 2 ; buy++) {
                for(int trancation = 0 ; trancation < k ; trancation++) {
                    if(buy == 1) {
                        dp[i][buy][trancation] = max(-prices[i] + dp[i+1][0][trancation], dp[i+1][1][trancation]);
                    } else {
                        dp[i][buy][trancation] = max(prices[i] + dp[i+1][1][trancation+1], dp[i+1][0][trancation]);
                    }
                }
            }
        }

        return dp[0][1][0];
    }
};