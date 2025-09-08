class Solution {
    int n,m;

    int solve(int index1, int index2, string s1, string s2,vector<vector<int>>& dp){

        if(index1 == 0 || index2 == 0) return 0;
        if(dp[index1][index2] != -1) return dp[index1][index2];
        if (s1[index1 - 1] == s2[index2 - 1]) {
            return dp[index1][index2] = 1 + solve(index1-1, index2-1, s1,s2,dp);
        }

        return dp[index1][index2] = max(solve(index1-1,index2,s1,s2,dp),solve(index1,index2-1,s1,s2,dp));
    }
public:
    int longestCommonSubsequence(string s1, string s2) {
        n = s1.length();
        m = s2.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1,0));

        for(int i =1; i <= n ; i++) {
            for(int j = 1; j <= m ; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else 
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    
        return dp[n][m];
    }
};