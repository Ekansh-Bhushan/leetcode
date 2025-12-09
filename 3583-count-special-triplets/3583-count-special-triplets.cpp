class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> left, right;
        int n = nums.size();
        long long ans = 0;

       
        for (int num : nums) {
            right[num]++;
        }

        for (int j = 0; j < n; ++j) {
            right[nums[j]]--; 

            int targetVal = nums[j] * 2;
            long long countLeft = left[targetVal];
            long long countRight = right[targetVal];

            ans = (ans + (countLeft * countRight) % MOD) % MOD;

            left[nums[j]]++; 
        }

        return ans;
    }
};
