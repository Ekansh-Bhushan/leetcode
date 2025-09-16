class Solution {
    int n;
public:
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        vector<int> dp(n,1);
        int maxi = 1;
        for(int i = 0 ; i < n ; i++) {
            for(int prev = 0 ; prev < i ; prev++) {
                if(nums[prev] < nums[i]) {
                    dp[i] = max(1+dp[prev],dp[i]);
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};