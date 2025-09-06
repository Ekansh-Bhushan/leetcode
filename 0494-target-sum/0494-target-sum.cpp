class Solution {

    // same question as count partition with diff = D Dp18 striver 
    int n;
    int findWays(vector<int> &num, int tar) {
        int n = num.size();

        vector<int> prev(tar + 1, 0);

        if (num[0] == 0)
            prev[0] = 2;  
        else
            prev[0] = 1; 

        if (num[0] != 0 && num[0] <= tar)
            prev[num[0]] = 1; 

        for (int ind = 1; ind < n; ind++) {
            vector<int> cur(tar + 1, 0);
            for (int target = 0; target <= tar; target++) {
                int notTaken = prev[target];

                int taken = 0;
                if (num[ind] <= target)
                    taken = prev[target - num[ind]];

                cur[target] = (notTaken + taken);
            }
            prev = cur;
        }
        return prev[tar];
    }

    int targetSum(int n, int target, vector<int>& arr) {
        int totSum = 0;
        for (int i = 0; i < n; i++) {
            totSum += arr[i];
        }

        if (totSum - target < 0 || (totSum - target) % 2 != 0)
            return 0;  

        return findWays(arr, (totSum - target) / 2);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return targetSum(nums.size(),target,nums);
    }
};