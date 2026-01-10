class Solution {
    int n, m;
    vector<vector<int>> dp;
    
    int solve(int row, int col, vector<vector<int>>& grid) {
        if (dp[row][col] != -1) return dp[row][col];

        int delRow[] = {-1, 0, 1};
        int best = 0;

        for (int i = 0; i < 3; i++) {
            int newRow = row + delRow[i];
            int newCol = col + 1;

            if (newRow >= 0 && newRow < n && newCol < m &&
                grid[newRow][newCol] > grid[row][col]) {

                best = max(best, 1 + solve(newRow, newCol, grid));
            }
        }

        return dp[row][col] = best;
    }

public:
    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n, vector<int>(m, -1));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i, 0, grid));
        }
        return ans;
    }
};
