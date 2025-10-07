class Solution {
    vector<int> findLPS(string str) {
        int n = str.length();
        vector<int> LPS(n);
        LPS[0] = 0;
        int i = 1;
        int len = 0;
        while(i < n) {
            if(str[i] == str[len]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if(len != 0) {
                    len = LPS[len - 1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
        return LPS;
    }
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        string temp = s + '-' + rev;
        vector<int> LPS = findLPS(temp);
        int longestLPSlength = LPS[temp.length() - 1];
        string culprit = rev.substr(0, s.length() - longestLPSlength);
        return culprit + s;
    }
};