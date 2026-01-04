class Solution {
    int findSumFourDivisors(int num){
        int cntDivisor = 0;
        int sum = 0;

        for(int i = 1; i*i <= num; i++) {

            if(num%i == 0) {
                int otherfact = num/i;
                if(otherfact == i) {
                    cntDivisor += 1;
                    sum += i;
                } else {
                    cntDivisor += 2;
                    sum += i + otherfact;
                }
            }

            if(cntDivisor > 4) {
                return 0;
            }
        }

        if(cntDivisor == 4) {
            return sum;
        }
        return 0;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for(auto num : nums) {
            ans += findSumFourDivisors(num);
        }
        return ans;
    }
};