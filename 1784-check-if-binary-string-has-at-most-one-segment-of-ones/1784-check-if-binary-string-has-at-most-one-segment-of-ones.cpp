class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0;

        for(int i = 1; i < s.length() ; i++) {
            if(s[i-1] == s[i]) {
                continue;
            } else if(s[i] == '1'){
                return false;
            }
        }
        return true;
    }
};