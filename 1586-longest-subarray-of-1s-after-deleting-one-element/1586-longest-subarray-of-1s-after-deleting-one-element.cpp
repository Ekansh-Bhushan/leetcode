class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        int cnt = 0;

        for(auto num : nums) {
            if(num == 1) cnt++;
            else{
                dp.push_back(cnt);
                cnt =0;
            }
        }
        dp.push_back(cnt);


        if(dp.size() == 1) return dp[0]-1;

        int maxLen =0;

        for(int i =0; i < dp.size() -1; i++ ){
            maxLen = max(maxLen, dp[i] + dp[i+1]);
        }

        return maxLen;
    }
};