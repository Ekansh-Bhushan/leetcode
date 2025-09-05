class Solution {
    int n ;
    int solve(int index, int amount, vector<int>& coins,vector<vector<int>>& dp) {
        if(amount == 0) return 0;
        if(index ==0) {
            if(amount%coins[0] == 0) return amount/coins[0];
            return 1e9;
        }

        if(dp[index][amount] != -1) return dp[index][amount];

        int notPick = solve(index-1 , amount, coins,dp);
        int pick = INT_MAX;
        if(amount >= coins[index]) {
            pick = 1 + solve(index,amount - coins[index],coins,dp);
        }

        return dp[index][amount] = min(pick,notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        n= coins.size();

        vector<vector<int>> dp(n+1 , vector<int> (amount + 1, -1));
        int ans = solve(n-1,amount,coins,dp);
        return ans == 1e9 ? -1 : ans;
    }
};