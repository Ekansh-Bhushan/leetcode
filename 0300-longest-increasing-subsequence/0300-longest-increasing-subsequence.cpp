class Solution {
    int n;

    int solve(int index, int prevIndex, vector<int>& nums,vector<vector<int>> &dp) {

        if(index == n) return 0;

        if(dp[index][prevIndex + 1] != -1) return dp[index][prevIndex + 1];

        int notPick = solve(index+1, prevIndex, nums,dp);

        int pick = 0;
        if(prevIndex == -1 || nums[index] > nums[prevIndex]){
            pick = 1 + solve(index+1, index, nums,dp);
        }

        return dp[index][prevIndex + 1] = max(pick,notPick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        
        vector<vector<int>> dp(n+1 , vector<int> (n+1,-1));

        return solve(0,-1,nums,dp);
    }
};