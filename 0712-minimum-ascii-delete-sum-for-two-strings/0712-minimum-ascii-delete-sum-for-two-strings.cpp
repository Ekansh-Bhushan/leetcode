class Solution {
    int n, m;

    int solve(int i, int j, string& s, string& t,vector<vector<int>>& dp) {
        if(i >= n && j >= m) {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(i >= n) {
            return dp[i][j] = t[j] + solve(i,j+1,s,t,dp);
        }

        if(j >= m) {
            return dp[i][j] = s[i] + solve(i+1,j,s,t,dp);
        }

        if(s[i] == t[j]) {
            return dp[i][j] = solve(i+1,j+1,s,t,dp);
        }

        int delete_si = s[i] + solve(i+1,j,s,t,dp);
        int delete_t1 = t[j] + solve(i,j+1,s,t,dp);

        return dp[i][j] = min(delete_si,delete_t1);
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        n = s1.length();
        m = s2.length();

        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));

        return solve(0,0,s1,s2,dp);
    }
};