class Solution {

    bool subsetSum(int i, int target, vector<int>& nums,vector<vector<int>>& dp){
        if(target == 0) return true;
        if(i == 0) return nums[i] == target;

        if(dp[i][target] != -1) return dp[i][target];

        bool notTaken = subsetSum(i-1, target,nums,dp);
        bool taken = false;
        if(nums[i] <= target) {
            taken = subsetSum(i-1, target - nums[i] , nums,dp);
        }

        return dp[i][target] = taken | notTaken;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int totalSum = 0;
        for(auto num : nums) {
            totalSum += num;
        }

        if(totalSum%2 != 0) return false;

        int k = totalSum/2;

        vector<vector<int>> dp(n+1, vector<int> (k+1, -1));

        return subsetSum(n-1,k,nums,dp);
    }
};