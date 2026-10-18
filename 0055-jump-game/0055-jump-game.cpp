class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<bool> dp(n, false);
        dp[0] = true;

        for(int i = 1; i < n; i++) {
            for(int j = n-1 ; j >= 0 ;j--) {
                if(dp[j] == true && j+nums[j] >= i) {
                    dp[i] = true;
                    break;
                }
            }
        } 

        return dp[n-1];
    }
};