class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0;
        int digitProduct = 1;
        int divisor = n;
        while(n > 0) {
            int digit = n%10;
            digitSum += digit;
            digitProduct *= digit;
            n /=10;
        }
        return divisor % (digitSum + digitProduct) == 0;
    }
};