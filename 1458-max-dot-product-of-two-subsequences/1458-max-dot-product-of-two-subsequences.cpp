class Solution {
    int n,m;

    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2,vector<vector<int>>& dp){
        if(i == n || j == m) return -1e9;

        if(dp[i][j] != -1) return dp[i][j];

        int val = nums1[i] * nums2[j];
        int take_i_j = nums1[i] * nums2[j] + solve(i+1,j+1, nums1, nums2,dp);
        int take_i = solve(i+1,j,nums1, nums2,dp);
        int take_j = solve(i,j+1,nums1, nums2,dp);
        return dp[i][j] = max({val,take_i_j,take_i,take_j});
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1 , -1));
        return solve(0,0,nums1,nums2,dp);
    }
};