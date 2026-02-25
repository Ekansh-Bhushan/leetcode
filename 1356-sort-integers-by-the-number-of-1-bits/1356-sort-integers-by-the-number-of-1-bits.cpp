class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(), [](int a, int b){ // O(nLogn)
            int countOnesA = __builtin_popcount(a); // O(1)
            int countOnesB = __builtin_popcount(b); // O(1)
            if(countOnesA == countOnesB) {
                return a < b;
            }
            return countOnesA < countOnesB;
        });

        return arr;
    }
};