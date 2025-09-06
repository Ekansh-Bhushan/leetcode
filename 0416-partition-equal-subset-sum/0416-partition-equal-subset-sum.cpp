class Solution {
    int n;

    bool solve(int index, int target , vector<int>& nums,vector<vector<int>>& dp){
        
        if(target == 0) return true;
        if(index == 0) {
            if(target == nums[0]) return true;
            return false;
        }
        if(dp[index][target] != -1) return dp[index][target];

        bool notPick = solve(index-1, target , nums,dp);
        bool pick = false;
        if(target >= nums[index]){
            pick = solve(index-1, target - nums[index], nums,dp);
        }

        return dp[index][target] = pick | notPick;
    }

public:
    bool canPartition(vector<int>& nums) {
        n = nums.size();

        int totalSum = 0;
        for(auto num : nums) totalSum += num;

        if(totalSum % 2 != 0) return false;

        int k = totalSum/2;


        vector<vector<int>> dp(n+1, vector<int> (k+1, -1));

        return solve(n-1,k,nums,dp);
    }
};