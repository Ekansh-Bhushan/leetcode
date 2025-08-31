class Solution {
    int n;
public:
    int solve(int index, int buy, int transction, vector<int>& prices,vector<vector<vector<int>>>& dp) {
        if(transction == 0) return 0;
        if(index == n ) return 0;

        if(dp[index][buy][transction]  != -1) return dp[index][buy][transction] ;

        int profit = 0;
        if(buy) {
            profit = max(-prices[index] + solve(index+1,0,transction,prices,dp),solve(index+1,1,transction,prices,dp));
        } else {
            profit = max(prices[index] + solve(index+1,1,transction-1,prices,dp),solve(index+1,0,transction,prices,dp));
        }

        return dp[index][buy][transction] = profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3,-1)));
        

        return solve(0,1,2,prices,dp);
    }
};