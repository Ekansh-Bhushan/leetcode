class Solution {
    int solve(int n , vector<int>& dp){
        if(n == 0) return 1;
        if(n == 1) return 1;

        if(dp[n] != -1) return dp[n];

        int left = climbStairs(n-1);
        int right = climbStairs(n-2);
        return dp[n] = left + right;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i<= n ;i++) {
            int left = dp[i-1];
            int right = dp[i-2];
            dp[i] = left + right;
        }
        return dp[n];
    }
};