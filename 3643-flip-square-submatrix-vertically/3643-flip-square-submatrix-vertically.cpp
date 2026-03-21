class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>> submat(k, vector<int>(k));

        // Copy submatrix
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                submat[i][j] = grid[x + i][y + j];
            }
        }

        // Reverse vertically
        reverse(submat.begin(), submat.end());

        // Write back to grid
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                grid[x + i][y + j] = submat[i][j];
            }
        }
        
        return grid;
    }
};
