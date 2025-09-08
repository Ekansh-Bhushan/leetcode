class Solution {
    int n;
    int m;
    int longestPalindromicSubsequence(string &s, string &t) {
        
        vector<int> prev(m+1, 0);

        vector<int> curr(m+1, 0);

        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= m ; j++) {
                if(s[i-1] == t[j-1]) {
                    curr[j] = 1 + prev[j-1];
                } else {
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }

        return prev[m];
    }
public:
    int minDistance(string word1, string word2) {
        n = word1.length();
        m = word2.length();
        int untouchedPart = longestPalindromicSubsequence(word1,word2);
        int deletion = n - untouchedPart;
        int insertion = m - untouchedPart;
        return deletion + insertion;
    }
};