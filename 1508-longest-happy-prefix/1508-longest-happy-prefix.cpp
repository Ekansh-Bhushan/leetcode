class Solution {
public:
    string longestPrefix(string s) {
        vector<int> lpsLength(s.length(), 0);
        int len = 0;
        int j = 1;
        
        while (j < s.length()) {
            if (s[j] == s[len]) {
                len++;
                lpsLength[j] = len;
                j++;
            } else {
                if (len > 0) {
                    len = lpsLength[len - 1];
                } else {
                    lpsLength[j] = 0;
                    j++;
                }
            }
        }
        
        return s.substr(0, lpsLength[s.size() - 1]);
    }
};