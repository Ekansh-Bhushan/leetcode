class Solution {
    int n;
public:
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        
        vector<vector<int>> dp(n+1 , vector<int> (n+1,0));

        for(int index = n-1; index >= 0 ; index--) {
            for(int prevIndex = index-1 ; prevIndex >= -1 ; prevIndex--) {

                int notPick = dp[index+1][prevIndex+1];

                int pick = 0;
                if(prevIndex == -1 || nums[index] > nums[prevIndex]){
                    pick = 1 + dp[index+1][index+1];
                }

                dp[index][prevIndex + 1] = max(pick,notPick);
            }
        }
        return dp[0][-1+1];
    }
};