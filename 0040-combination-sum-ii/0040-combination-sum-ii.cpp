class Solution {
    void solve(int index, int target, vector<int>& ds, vector<vector<int>>& ans, vector<int>& candidates) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i-1]) continue; // skip duplicates
            if (candidates[i] > target) break; // no point in continuing

            ds.push_back(candidates[i]);
            solve(i+1, target - candidates[i], ds, ans, candidates); // move to next index
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // sort first
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, target, ds, ans, candidates);
        return ans;
    }
};
