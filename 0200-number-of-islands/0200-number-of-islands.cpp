class Solution {
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j , int n , int m ) {
        vis[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,-1,0,1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k = 0 ; k < 4 ; k++)  {
                int newRow = row + delRow[k];
                int newCol = col + delCol[k];
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && 
                   !vis[newRow][newCol] && grid[newRow][newCol] == '1') {
                    vis[newRow][newCol] = 1;
                    q.push({newRow,newCol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n , vector<int> (m,0));

        int cnt = 0;
        for(int i = 0; i < n ;i ++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    cnt++;
                    bfs(grid, vis, i, j, n, m);
                }
            }
        }

        return cnt;
    }
};
