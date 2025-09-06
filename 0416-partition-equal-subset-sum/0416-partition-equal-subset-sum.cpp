class Solution {
    int n;



public:
    bool canPartition(vector<int>& nums) {
        n = nums.size();

        int totalSum = 0;
        for(auto num : nums) totalSum += num;

        if(totalSum % 2 != 0) return false;

        int k = totalSum/2;


        
        vector<bool> prev(k+1, 0);
        vector<bool> curr(k+1, 0);


        for(int i = 0; i < n ; i++) {
            prev[0] = true;
        }

        if(k >= nums[0]) prev[nums[0]] = true;

        for(int index = 1 ; index < n ; index++) {
            for(int target = 0; target<=k ;target++){
                bool notPick = prev[target];
                bool pick = false;
                if(target >= nums[index]){
                    pick = prev[ target - nums[index]];
                }

                curr[target] = pick | notPick;
            }
            prev = curr;
        }
        return prev[k];
    }
};