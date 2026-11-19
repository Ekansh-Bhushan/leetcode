class Solution {
public:
    int n;
    int t[100001];
    const int MOD = 1e9+7;
    int solve(int i, string &s, int &k) {
        if(i >= n) {
            return 1;
        }

        if(s[i] == '0') {
            return 0;
        }

        if(t[i] != -1){
            return t[i];
        }
        long num = 0;
        long long ans = 0;

        for(int end = i; end < n ; end++) {
            num = num * 10 + (s[end] - '0');
            if(num > k) {
                break;
            }
            ans = ( ans + solve(end+1, s,k)%MOD)%MOD;
        }

        return t[i] = ans % MOD;
    }
    int numberOfArrays(string s, int k) {
        n = s.length();
        memset(t,-1, sizeof(t));
        return solve(0,s,k) %MOD;
    }
};