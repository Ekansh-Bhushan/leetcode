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

        int k = totalSum/2;

        vector<vector<bool>> dp(n+1, vector<bool> (k + 1,false));


        for(int i = 0; i < n ; i++) {
            dp[i][0] = true;
        }

        if(nums[0] <= k)
            dp[0][nums[0]] = true;

        for(int index =1; index < n ; index++) {
            for(int target = 1 ; target <= k; target++) {
                bool notTaken = dp[index - 1][target];
                bool Taken = false;
                if(nums[index] <= target) {
                    Taken = dp[index - 1][target - nums[index]];
                }
                dp[index][target]  = Taken || notTaken;
            }
        }

        return dp[n-1][k];
    }
};