class Solution {
public:
    //brute force
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, right = 0;
        int maxCount = 0;

        while (right < nums.size()) {
            if (nums[right] == 1) {
                maxCount = max(maxCount, right - left + 1);
            } else {
                left = right + 1; 
            }
            right++;  // Expand window
        }

        return maxCount;
    }

};