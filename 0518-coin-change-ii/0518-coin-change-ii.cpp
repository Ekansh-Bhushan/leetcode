class Solution {
    int n;

    int solve(int index, int target, vector<int>& arr,vector<vector<int>>& dp) {
        
        if(index == 0) {
            return target % arr[0] == 0;
        }

        if(dp[index][target] != -1) return dp[index][target];

        int notPick = solve(index-1 , target, arr,dp);
        int pick = 0;
        if(target >= arr[index]){
            pick = solve(index,target - arr[index] , arr,dp);
        }

        return dp[index][target] = pick+notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        n = coins.size();

        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};