class Solution {
    const int MOD = 1e9+7;
    int solve(int length, int low, int high, int zero, int one,vector<int>& dp){
        if(length > high) return 0;

        if(dp[length] != -1) return dp[length] ;

        int count = (length >= low) ? 1 : 0;

        int addZero = solve(length + zero , low, high, zero, one,dp);
        int addOne = solve(length + one , low, high, zero, one,dp);

        return dp[length] = (count + addZero + addOne)%MOD;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(100001, -1);
        return solve(0,low,high,zero,one,dp);
    }
};