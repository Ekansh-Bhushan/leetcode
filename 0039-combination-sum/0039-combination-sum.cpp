class Solution {
    int n;
    void solve(int index, vector<int>& ds, int target,vector<int>& arr, vector<vector<int>>& ans) {
        if(index == n) {
            if(target ==0 ){
                ans.push_back(ds);
            }
            return;
        }

        if(arr[index] <= target) {
            ds.push_back(arr[index]);
            solve(index, ds, target - arr[index], arr,ans);
            ds.pop_back();
        }

        solve(index+1, ds, target, arr, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        n = candidates.size();

        solve(0,ds,target,candidates,ans);

        return ans;
    }
};