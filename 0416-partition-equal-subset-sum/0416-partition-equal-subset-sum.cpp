class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(auto x : nums) {
            totalSum += x;
        }

        if(totalSum%2 == 1) return false;

        int k = totalSum/2;

        vector<bool> prev(k + 1,false), curr(k + 1,false) ;


        for(int i = 0; i < n ; i++) {
            prev[0] = true;
        }

        if(nums[0] <= k)
            prev[nums[0]] = true;

        for(int index =1; index < n ; index++) {
            for(int target = 1 ; target <= k; target++) {
                bool notTaken = prev[target];
                bool Taken = false;
                if(nums[index] <= target) {
                    Taken = prev[target - nums[index]];
                }
                curr[target]  = Taken || notTaken;
            }
            prev = curr;
        }

        return prev[k];
    }
};