class Solution {
    int n;

public:
    bool canPartition(vector<int>& nums) {
        n = nums.size();

        int totalSum = 0;
        for(int i = 0 ; i < n ; i++) {
            totalSum += nums[i];
        }

        if(totalSum % 2 != 0) return false;

        int k = totalSum/2;
        vector<bool> prev(k+1,false);
        vector<bool> curr(k+1,false);
        
        
        prev[0]=true;
        curr[0] = true;
        

        if(nums[0] <= k) prev[nums[0]] = true;

        for(int i= 1 ;i < n ; i++){
            for(int target = 0; target <= k ;target++) {
                bool notPick = prev[target];

                bool pick = false;

                if(target >= nums[i]){
                    pick = prev[target - nums[i]];
                }

                curr[target] = pick | notPick;
            }
            prev = curr;
        }

        return prev[k];
    }
};