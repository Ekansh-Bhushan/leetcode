class Solution {
    bool solve(string& ans) {
        int l = 0 ; 
        int r = ans.length() -1;
        while(l < r) {
            if(ans[l] != ans[r]) return false;
            r--;
            l++;
        }
        return true;
    }
public:
    bool isPalindrome(string s) {
        string ans = "";
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] >= 'a' && s[i] <= 'z') ans+=s[i];
            else if(s[i] >= 'A' && s[i] <= 'Z') ans += s[i] + 32;
            else if(s[i] >= '0' && s[i] <= '9') ans += s[i];
        }

        return solve(ans);
    }
};