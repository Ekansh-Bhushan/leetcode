class Solution {
    int n,m;
    int dfs(int row, int col, vector<vector<int>>& grid) {
        int sum = grid[row][col];
        grid[row][col] = 0;

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,-1,0,1};

        for(int i = 0; i < 4 ; i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] != 0){
                sum += dfs(newRow,newCol,grid);
            }
        }
        return sum;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int maxFish = 0;

        for(int i = 0; i < n ; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0) {
                    int fish = dfs(i,j,grid);
                    maxFish = max(maxFish,fish);
                }
            }
        }

        return maxFish;
    }
};