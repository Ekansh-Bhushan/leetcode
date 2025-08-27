class Solution {
    int n;

    int solve(int index, int transaction,int k,vector<int>& prices,vector<vector<int>>& dp) {
        if(index == n || transaction == 2*k ) return 0;


        if(dp[index][transaction] != -1) return dp[index][transaction];

        int profit = 0;


        if(transaction%2 == 0) {
            profit = max(-prices[index] + solve(index+1 , transaction + 1, k , prices,dp),solve(index+1 , transaction, k , prices,dp) );
        } else {
            profit = max(prices[index] + solve(index+1 , transaction + 1, k , prices,dp),solve(index+1 , transaction, k , prices,dp) );
        }

        return dp[index][transaction] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2*k+1,-1));
        return solve(0,0,k,prices,dp);
       
    }
};