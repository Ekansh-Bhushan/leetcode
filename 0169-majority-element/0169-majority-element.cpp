class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int ele;
        int cnt = 0;
        for(int i = 0 ; i < n ; i++) {
            if(cnt == 0) ele = nums[i];
            if(nums[i] == ele ) cnt++;
            else if(nums[i] != ele) cnt--;
        }

        int finalcnt = 0;

        for(int i = 0 ; i < n ; i++) {
            if(ele == nums[i]) finalcnt++;
        }

        if(finalcnt > n/2) return ele;
        else return -1;
    }
};