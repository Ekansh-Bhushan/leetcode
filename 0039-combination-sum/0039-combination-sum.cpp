class Solution {
    void solve(int index, int target, vector<int>& ds,vector<int>& candidates, vector<vector<int>>& ans) {

        if(index == candidates.size()) {
            if(target == 0) {
                ans.push_back(ds);

            }
            return;
        }

        if(target < 0){
            return;
        }

        ds.push_back(candidates[index]);
        solve(index,target - candidates[index], ds,candidates,ans);
        ds.pop_back();

        solve(index + 1,target,ds,candidates,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,target,ds,candidates,ans);
        return ans;
    }
};