class Solution {
    int n;



public:
    bool canPartition(vector<int>& nums) {
        n = nums.size();

        int totalSum = 0;
        for(auto num : nums) totalSum += num;

        if(totalSum % 2 != 0) return false;

        int k = totalSum/2;


        vector<vector<bool>> dp(n+1, vector<bool> (k+1, 0));


        for(int i = 0; i < n ; i++) {
            dp[i][0] = true;
        }

        if(k >= nums[0]) dp[0][nums[0]] = true;

        for(int index = 1 ; index < n ; index++) {
            for(int target = 0; target<=k ;target++){
                bool notPick = dp[index-1][target];
                bool pick = false;
                if(target >= nums[index]){
                    pick = dp[index-1][ target - nums[index]];
                }

                dp[index][target] = pick | notPick;
            }
        }
        return dp[n-1][k];
    }
};