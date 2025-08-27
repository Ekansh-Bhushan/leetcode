class Solution {
    int n;

    int solve(int index, int buy, vector<int>& prices,vector<vector<int>>& dp) {
        if(index == n) return 0;

        if(dp[index][buy] != -1) return dp[index][buy];
        int profit = 0;

        if(buy) {
            profit = max(-prices[index] + solve(index+1,!buy,prices,dp) , solve(index+1, buy ,prices,dp));
        } else {
            profit = max(prices[index] + solve(index+1,!buy,prices,dp) , solve(index+1,buy,prices,dp));
        }

        return dp[index][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return solve(0,1,prices,dp);
    }
};