class Solution {
    int n,m;

public:
    int longestCommonSubsequence(string s1, string s2) {
        n = s1.length();
        m = s2.length();
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);

        for(int i =1; i <= n ; i++) {
            for(int j = 1; j <= m ; j++) {
                if(s1[i-1] == s2[j-1]) {
                    curr[j] = 1 + prev[j-1];
                } else 
                    curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
    
        return prev[m];
    }
};