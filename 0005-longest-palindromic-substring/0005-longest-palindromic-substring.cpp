class Solution {
    string checkPalindrom;
    bool isPalindrom(int l, int r,vector<vector<int>>& dp) {
        if(l >= r) return dp[l][r] = 1;

        if(dp[l][r] != -1) return dp[l][r];

        if(checkPalindrom[l] == checkPalindrom[r]) return dp[l][r] = isPalindrom(l+1,r-1,dp);
        return dp[l][r] =  0;
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 0;
        int startingPoint = -1;
        checkPalindrom = s;
        
        vector<vector<int>> dp(1001, vector<int> (1001,-1));

        for(int i = 0 ; i < n ; i++) {
            for(int j = i ; j < n ; j++) {
                if(isPalindrom(i,j,dp)) {
                    if(maxLen < j - i + 1) {
                        maxLen = j - i + 1;
                        startingPoint = i;
                    }
                }
            }
        }

        return s.substr(startingPoint,maxLen);
    }
};