class Solution {
    int n;
public:
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        
        vector<int> ahead(n+1,0);
        vector<int> curr(n+1,0);

        for(int index = n-1; index >= 0 ; index--) {
            for(int prevIndex = index-1 ; prevIndex >= -1 ; prevIndex--) {

                int notPick = ahead[prevIndex+1];

                int pick = 0;
                if(prevIndex == -1 || nums[index] > nums[prevIndex]){
                    pick = 1 + ahead[index+1];
                }

                curr[prevIndex + 1] = max(pick,notPick);
            }
            ahead = curr;
        }
        return ahead[-1+1];
    }
};