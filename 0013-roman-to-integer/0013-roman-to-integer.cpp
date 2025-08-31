class Solution {
public:
    unordered_map<char,int> mpp = {{'I', 1}, {'V', 5}, {'X',10}, {'L',50}, {'C',100}, {'D',500},{'M',1000}};

    int romanToInt(string s) {
        int ans = 0;
        int n = s.length();

        for(int i = 0 ; i < s.length() ; i++) {
            if(i+1 < n && mpp[s[i]] < mpp[s[i+1]]) {
                ans -= mpp[s[i]];
            } else {
                ans += mpp[s[i]];
            }
        }
        return ans;
    }
};