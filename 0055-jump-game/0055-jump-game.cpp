class Solution {
public:
    int dp[10001];
    int n;
    bool solve(int i, vector<int>& nums) {
        if(i == n-1) {
            return dp[i] = true;
        }

        if(i > n-1) {
            return dp[i] = false;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        for(int idx = 1; idx <= nums[i]; idx++) {
            if (solve(i + idx, nums)) {
                return dp[i] = true;
            }
        }

        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1 , sizeof(dp));
        return solve(0, nums);
    }
};