class Solution {
    int n;
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3,0)));


        for(int i = n-1 ; i >= 0 ; i--) {
            for(int buy = 0 ; buy < 2 ; buy++) {
                for(int transaction = 1; transaction < 3 ;transaction++) {
                    if(buy == 1) {
                        dp[i][buy][transaction] = max(-prices[i] + dp[i+1][0][transaction], dp[i+1][1][transaction]);
                    } else {
                        dp[i][buy][transaction] = max(prices[i] + dp[i+1][1][transaction-1], dp[i+1][0][transaction]);
                    }
                }
            }
        }
        

        return  dp[0][1][2];
    }
};