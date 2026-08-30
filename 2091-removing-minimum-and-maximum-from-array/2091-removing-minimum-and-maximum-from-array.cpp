class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(),nums.end());
        int minEle = *min_element(nums.begin(),nums.end());
        int minEleIdx = 0;
        int maxEleIdx = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == maxEle) {
                maxEleIdx = i;
            }
            if(nums[i] == minEle) {
                minEleIdx = i;
            }
        }
        // short way for index int minEleIdx = *min_element(nums.begin(),nums.end()) - nums.begin();
        int leftIndex = min(maxEleIdx,minEleIdx);
        int rightIndex = max(maxEleIdx,minEleIdx);


        // Case 1 
        int stepsOne = leftIndex + 1 + n - rightIndex;

        // Case 2
        int stepsSecond = rightIndex + 1;

        // Case 3
        int stepsThird = n - leftIndex;

        return min({stepsOne, stepsSecond, stepsThird});
    }
};