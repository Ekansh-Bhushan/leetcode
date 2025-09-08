class Solution {
    int n,m;
    string longestCommonSubsequnce(string &s, string &t) {

        vector<vector<int>> dp(n+1, vector<int> (m+1,0));

        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1; j <=m ;j++) {
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        string ans = "";

        int i = n ;
        int j = m;

        while( i > 0 && j > 0) {
            if(s[i-1] == t[j-1]) {
                ans += s[i-1];
                i--;
                j--;
            } else if(dp[i-1][j] > dp[i][j-1]) {
                ans += s[i-1];
                i--;
            } else {
                ans += t[j-1];
                j--;
                
            }
        }

        while(i >0 ) {
            ans += s[i-1];
            i--;
        }

        while(j > 0) {
            ans += t[j-1];
            j--;
        }


        return ans;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        n = str1.length();
        m = str2.length();

        string ans = longestCommonSubsequnce(str1,str2);

        reverse(ans.begin(),ans.end());
        return ans;
    }
};