class Solution {
public:
    int numSteps(string s) {
        int n = s.length();
        int result = n - 1;
        int carry = 0;
        for (int i = n - 1; i > 0; i--) {
            if (s[i] - '0' + carry == 1) {
                result++;
                carry = 1;
            }
        }
        return result + carry;
    }
};