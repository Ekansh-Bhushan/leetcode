class Solution {
    bool isPalindrom(string& s) {
        int n = s.length();
        int l = 0 ;
        int r = n-1;
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        } 
        return true;
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 0;
        string maxString = "";
        for(int i = 0 ; i < n ; i++) {
            string substring = "";
            for(int j = i ; j < n ; j++) {
                substring += s[j];
                if(isPalindrom(substring)) {
                    if(maxLen < j - i + 1) {
                        maxLen = j - i + 1;
                        maxString = substring;
                    }
                }
            }
        }

        return maxString;
    }
};