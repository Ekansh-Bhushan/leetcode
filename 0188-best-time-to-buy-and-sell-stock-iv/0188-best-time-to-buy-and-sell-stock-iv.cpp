class Solution {
    int n;

    int solve(int index, int canBuy, int trancation,vector<int>& prices,vector<vector<vector<int>>>& dp) {
        if(index == n || trancation == 0) return 0;

        if(dp[index][canBuy][trancation] != -1) return dp[index][canBuy][trancation];
        
        int profit = 0;
        if(canBuy) {
            profit = max(-prices[index] + solve(index + 1, 0, trancation, prices,dp), solve(index + 1,1,trancation, prices,dp));
        } else {
            profit = max(prices[index] + solve(index + 1, 1, trancation-1, prices,dp), solve(index + 1,0,trancation, prices,dp));
        }

        return dp[index][canBuy][trancation] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1,-1)));

        return solve(0,1,k,prices,dp);
    }
};