class Solution {
    string checkPalindrom;
    bool isPalindrom(int l, int r) {
        int n = checkPalindrom.length();
        while(l < r) {
            if(checkPalindrom[l] != checkPalindrom[r]) return false;
            l++;
            r--;
        } 
        return true;
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 0;
        int startingPoint = -1;
        checkPalindrom = s;
        for(int i = 0 ; i < n ; i++) {
            for(int j = i ; j < n ; j++) {
                if(isPalindrom(i,j)) {
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