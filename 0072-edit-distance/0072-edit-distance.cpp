class Solution {
    int n,m;
public:
    int minDistance(string s, string t) {
        n = s.length();
        m = t.length();

        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);


        for(int j = 0; j <= m ; j++) {
            prev[j] = j;
        }

        for(int i = 1 ; i <= n ; i++) {
            curr[0] = i; 
            for(int j= 1; j<= m; j++) {
                if(s[i-1] == t[j-1]) {
                    curr[j] = prev[j-1];
                }else {
                    curr[j] = 1 + min(curr[j-1], min(prev[j], prev[j-1]));
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};