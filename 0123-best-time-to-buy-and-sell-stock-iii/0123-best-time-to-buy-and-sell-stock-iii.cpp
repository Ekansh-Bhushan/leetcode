class Solution {
    int n;
    int solve(int index, int tranction, vector<int>& prices,vector<vector<int>>& dp) {
        if(index == n || tranction == 4) return 0;
        if(dp[index][tranction] != -1) return dp[index][tranction];
        int profit = 0;
        if(tranction % 2 == 0) {
            profit = max(-prices[index] + solve(index+1,tranction+1,prices,dp), solve(index+1,tranction,prices,dp));
        } else {
            profit = max(prices[index] + solve(index+1,tranction+1,prices,dp), solve(index+1,tranction,prices,dp));
        }

        return dp[index][tranction] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();

        vector<vector<int>> dp(n+1, vector<int> (4,-1));

        return solve(0,0,prices,dp);
    }
};