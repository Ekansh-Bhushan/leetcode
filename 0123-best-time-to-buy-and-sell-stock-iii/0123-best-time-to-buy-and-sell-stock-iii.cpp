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
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0,1,2,prices,dp);
    }
};