class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        
        int counter = 0;
        int result = 0;

        while(n){
            int remainder = n%2;
            if(remainder == 0){
                result += (1 << counter); // 2^counter
            }
            counter++;
            n /= 2;
        }
        return result;
    }
};