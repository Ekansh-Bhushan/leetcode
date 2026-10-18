class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int maxReachable = 0;

        for(int i = 0; i < n; i++) {
            if(maxReachable < i) {
                return false;
            }

            maxReachable = max(maxReachable, nums[i] + i);
        }

        return true;
    }
};