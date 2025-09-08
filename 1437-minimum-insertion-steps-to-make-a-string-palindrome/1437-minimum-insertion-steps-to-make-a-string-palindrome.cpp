class Solution {
    int n;

    int longestPalindromicSubsequence(string &s, string &t) {
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= n ; j++) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                     dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n][n];
    }
public:
    int minInsertions(string s) {
        n = s.length();
        string t =s;
        reverse(t.begin(),t.end());

        int longestPS = longestPalindromicSubsequence(s,t);

        return n - longestPS;
    }
};