class Solution {
    int n,m;

    int solve(int i, int j, string &s, string &t,vector<vector<int>>& dp) {
        if(i <0) return j+1;
        if(j < 0) return i+1;
        
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) {
            return dp[i][j] = solve(i-1,j-1,s,t,dp);
        }

        return dp[i][j] = 1 + min(solve(i,j-1,s,t,dp), min(solve(i-1,j,s,t,dp) , solve(i-1,j-1,s,t,dp)));
    }
public:
    int minDistance(string word1, string word2) {
        n = word1.length();
        m = word2.length();

        vector<vector<int>> dp(n+1 , vector<int> (m+1, -1));
        return solve(n-1,m-1,word1,word2,dp);
    }
};