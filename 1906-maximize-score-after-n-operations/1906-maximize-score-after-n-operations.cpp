class Solution {
    int solve(vector<int>& nums, vector<bool>& visited, int operation, unordered_map<vector<bool>,int>& mpp) {

        if(mpp.find(visited) != mpp.end()) {
            return mpp[visited];
        }
        int maxSource =0;
        int n = nums.size();


        for(int i = 0 ; i <= n-2 ; i++) {
            if(visited[i]) continue;
            for(int j= i+1; j < n ;j++) {
                if(visited[j]) continue;

                visited[i] = true;
                visited[j] = true;

                int source = operation * __gcd(nums[i],nums[j]);    
                int remaing = solve(nums,visited,operation+1,mpp);

                maxSource = max(maxSource,source+remaing);

                visited[i] = false;
                visited[j] = false;
            }
        }

        return mpp[visited] = maxSource;
    }
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n,false);


        unordered_map<vector<bool>,int> mpp;
        return solve(nums,visited,1,mpp);
    }
};