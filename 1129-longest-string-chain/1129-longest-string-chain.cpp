class Solution {
    bool checkPossible(const string &s1, const string &s2) {
        if(s1.length() != s2.length() + 1) return false;

        int first = 0;
        int second = 0;

        while(first < s1.length()) {
            if(second < s2.length() && s1[first] == s2[second]) {
                first++;
                second++;
            } else {
                first++;
            }
        }

        return second == s2.length();
    }

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;

        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.length() < b.length();
        });

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(checkPossible(words[i], words[j]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};
