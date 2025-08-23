class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,-1);  // stores last seen index of characters
        int n = s.length();
        int l = 0, r = 0;
        int maxLen = 0;

        while (r < n) {
            if (hash[s[r]] != -1 && hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }

            int len = r - l + 1;
            maxLen = max(maxLen, len);

            hash[s[r]] = r;

            r++;
        }

        return maxLen;
    }
};
