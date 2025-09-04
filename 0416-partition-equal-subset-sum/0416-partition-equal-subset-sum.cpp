class Solution {
    int n;

public:
    bool canPartition(vector<int>& nums) {
        n = nums.size();

        int totalSum = 0;
        for(int i = 0 ; i < n ; i++) {
            totalSum += nums[i];
        }

        if(totalSum % 2 != 0) return false;

        vector<vector<bool>> dp(n+1,vector<bool> ((totalSum/2)+1,false));
        int k = totalSum/2;
        
        for(int i= 0 ;i < n ;i++) {
            dp[i][0]=true;
        }

        if(nums[0] <= k) dp[0][nums[0]] = true;

        for(int i= 1 ;i < n ; i++){
            for(int target = 0; target <= k ;target++) {
                bool notPick = dp[i-1][target];

                bool pick = false;

                if(target >= nums[i]){
                    pick = dp[i-1][target - nums[i]];
                }

                dp[i][target] = pick | notPick;
            }
        }

        return dp[n-1][k];
    }
};