class Solution {
    static int findOnes(int n) {
        int cnt = 0;
        while(n != 0) {
            cnt += (n&1);
            n >>= 1;
        }
        return cnt;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(), [](int a, int b){
            int countOnesA = findOnes(a);
            int countOnesB = findOnes(b);
            if(countOnesA == countOnesB) {
                return a < b;
            }
            return countOnesA < countOnesB;
        });

        return arr;
    }
};