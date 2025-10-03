class Solution {
    vector<int> getLPS(string& pattern) {
        int m = pattern.length();
        vector<int> LPS(m);
        LPS[0] = 0;
        int i = 1;
        int len = 0;

        while(i < m) {
            if(pattern[i] == pattern[len]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if(len != 0) {
                    len = LPS[len-1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }

        return LPS;
    }
public:
    bool rotateString(string s, string goal) {

        if(s.length() != goal.length()) {
            return false;
        }
        string txt = s + s;

        int n = txt.length();
        int m = goal.length();

        vector<int> LPS = getLPS(goal);

        int i = 0;
        int j = 0;

        while( i < n) {
            if(txt[i] == goal[j]) {
                i++;
                j++;
            }
            if(j == m) {
                return true;
            } else if(txt[i] != goal[j]){
                if(j != 0) {
                    j = LPS[j-1];
                } else {
                    i++;
                }
            }
        }

        return false;
    }
};