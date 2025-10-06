class Solution {
    void solve(int sum,int ind, int k, vector<int>& ds , vector<vector<int>>& ans) {
        if(sum == 0 && k == ds.size()) {
            ans.push_back(ds);
            return;
        }

        if(sum <= 0 || k < ds.size()) return;

        for(int i = ind ; i <= 9 ; i++) {
            if(i <= sum ) {
                ds.push_back(i);
                solve(sum - i , i+1 , k , ds, ans);
                ds.pop_back();
            }else {
                break;
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;

        solve(n,1,k,ds,ans);

        return ans;
    }
};