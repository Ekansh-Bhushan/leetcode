class Solution {
public:
    //brute force
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxNumber = 0;
        int currentCount = 0;

        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                currentCount++;
                maxNumber = max(maxNumber, currentCount);
            } else {
                currentCount = 0;
            }
        }

        return maxNumber;
    }

};