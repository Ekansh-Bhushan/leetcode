class Solution {

    int solve(int index, int amount, vector<int>& coins,vector<vector<int>>& dp) {
        if(amount == 0) return 0;
        if(index == coins.size()) return 1e7;
        if(amount < coins[index]) return 1e7;

        if(dp[index][amount] != -1) return dp[index][amount];

        int notUsedCoin = solve(index+1, amount,coins,dp);
        int usedCoin = 1 + solve(index, amount - coins[index], coins,dp);
        

        return dp[index][amount] = min(usedCoin, notUsedCoin);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        sort(coins.begin(),coins.end());
        int n= coins.size();

        vector<vector<int>> dp(n+1 , vector<int> (10001, -1));
        int ans = solve(0,amount,coins,dp);
        return ans == 1e7 ? -1 : ans;
    }
};