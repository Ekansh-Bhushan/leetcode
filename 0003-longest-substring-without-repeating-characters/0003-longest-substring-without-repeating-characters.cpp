class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxlen = 0;
        vector<int> hash(255,0);
        for(int i = 0; i < n ; i++) {
            vector<bool> visited(256, false); 
            for(int j = i; j < n ; j++) {
                // Check if the character s[j] has been seen
                if(visited[s[j]]) {
                    break;
                } else {
                    visited[s[j]] = true;
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }
        return maxlen;

    }
};
