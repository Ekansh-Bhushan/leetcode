class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};

        int n = matrix.size();
        int m = matrix[0].size();
        map<int, vector<int>> mpp;

        // Group elements by diagonal key (i+j)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mpp[i + j].push_back(matrix[i][j]);
            }
        }

        vector<int> res;

        for(auto &it : mpp) {
            if(it.first % 2 == 0) {
                // Reverse for even diagonals
                reverse(it.second.begin(), it.second.end());
            }
            // Insert all elements into result
            for(int val : it.second) {
                res.push_back(val);
            }
        }

        return res;
    }
};
