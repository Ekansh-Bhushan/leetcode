class Solution {
    bool subsetSum(int index, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(index == 0) return target == nums[0];

        if(dp[index][target] != -1) return dp[index][target];

        bool notTaken = subsetSum(index - 1, target, nums,dp);
        bool Taken = false;
        if(nums[index] <= target) {
            Taken = subsetSum(index - 1, target - nums[index] , nums,dp);
        }
        return dp[index][target]  = Taken || notTaken;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(auto x : nums) {
            totalSum += x;
        }

        if(totalSum%2 == 1) return false;

        int target = totalSum/2;

        vector<vector<int>> dp(n+1, vector<int> (target + 1,-1));

        return subsetSum(n-1,target,nums,dp);
    }
};