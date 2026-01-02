class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mpp;
        for(int i = 0; i < n ; i++) {
            mpp[nums[i]]++;
        }

        for(auto mp : mpp ){
            if(mp.second == n/2) return mp.first;
        }
        return -1;
    }
};