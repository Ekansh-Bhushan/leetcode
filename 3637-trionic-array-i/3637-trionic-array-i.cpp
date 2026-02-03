class Solution {
    bool strictlyIncreasing(int start, int end, vector<int>& nums) {
        if (end - start + 1 < 2) return false;          // need ≥2 elements
        for (int i = start; i < end; ++i)
            if (nums[i] >= nums[i+1]) return false;
        return true;
    }

    bool strictlyDecreasing(int start, int end, vector<int>& nums) {
        if (end - start + 1 < 2) return false;          // need ≥2 elements
        for (int i = start; i < end; ++i)
            if (nums[i] <= nums[i+1]) return false;
        return true;
    }

public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;                        // minimal length is 4

        for (int i = 1; i <= n-3; ++i) {                // first split at i
            if (!strictlyIncreasing(0, i, nums)) continue;
            for (int j = i+1; j <= n-2; ++j) {          // second split at j
                if (strictlyDecreasing(i, j, nums) &&
                    strictlyIncreasing(j, n-1, nums))
                    return true;
            }
        }
        return false;
    }
};
