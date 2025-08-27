class Solution {
    int n;
    int solve(int index, int canBuy, int transaction, vector<int>& prices,vector<vector<vector<int>>>& dp) {
        if(index == n || transaction == 0) return 0;

        if(dp[index][canBuy][transaction] != -1) return dp[index][canBuy][transaction];
        int profit = 0;

        if(canBuy) {
            profit = max(-prices[index] + solve(index+1,!canBuy, transaction, prices,dp), solve(index+1,canBuy,transaction,prices,dp));
        } else {
            profit = max(prices[index] + solve(index+1,!canBuy, transaction - 1, prices,dp), solve(index+1,canBuy,transaction,prices,dp));
        }

        return dp[index][canBuy][transaction] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        // for(int i = 0 ; i < n-1 ; i++) {
        //     for(int buy = 0 ; buy < 2 ; buy++) {
        //         dp[i][buy][0] = 0;
        //     }
        // }

        // for(int buy = 0 ; buy < 2 ; buy++) {
        //     for(int transaction = 0; transaction < 3 ;transaction++) {
        //         dp[n][buy][transaction] = 0;
        //     }
        // }

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
        return dp[0][1][2];
    }
};