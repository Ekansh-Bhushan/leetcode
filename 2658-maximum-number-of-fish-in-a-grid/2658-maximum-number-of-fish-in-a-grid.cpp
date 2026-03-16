class Disjoint{
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    Disjoint(int n) {
        parent.resize(n);
        rank.resize(n,0);
        size.resize(n,1);

        for(int i = 0; i < n ;i++) {
            parent[i] = i;
        }
    }
    void setSize(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n ; i++) {
            for(int j = 0; j < m; j++) {
                size[i * m + j] = grid[i][j];
            }
        }
    }
    int findParent(int x) {
        if(x == parent[x]) return x;
        return parent[x] = findParent(parent[x]);
    }

    void Union(int x, int y){
        int xParent = findParent(x);
        int yParent = findParent(y);

        if(xParent == yParent) {
            return;
        }

        //  =======Union by rank========
        // if(rank[xParent] > rank[yParent]) {
        //     parent[yParent] = xParent;
        // } else if(rank[xParent] < rank[yParent]) {
        //     parent[xParent] = yParent;
        // } else {
        //     parent[xParent] = yParent;
        //     rank[yParent]++;
        // }

        if(size[xParent] > size[yParent]) {
            parent[yParent] = xParent;
            size[xParent] += size[yParent];
        } else if(size[xParent] < size[yParent]) {
            parent[xParent] = yParent;
            size[yParent] += size[xParent];
        } else {
            parent[xParent] = yParent;
            size[yParent] += size[xParent];
        }
    }

    int getMaxSizeNumber() {
        return *max_element(size.begin(),size.end());
    }
};
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

    int bfs(int row, int col, vector<vector<int>>& grid) {
        int sum = grid[row][col];
        

        queue<pair<int,int>> q;
        q.push({row,col});
        grid[row][col] = 0;

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,-1,0,1};

        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k = 0; k < 4 ; k++) {
                int newRow = i + delRow[k];
                int newCol = j + delCol[k];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] != 0){
                    sum += grid[newRow][newCol];
                    grid[newRow][newCol] = 0;
                    q.push({newRow,newCol});
                }
            }
        }

        return sum;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int totalParent = n*m;

        Disjoint DSU(totalParent);

        DSU.setSize(grid);

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,-1,0,1};

        for(int i = 0; i < n ; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0) {
                    int index = i*m + j;
                    for(int k = 0; k < 4 ; k++) {
                        int newRow = i + delRow[k];
                        int newCol = j + delCol[k];
                        if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] != 0){
                            int newIndex = newRow*m + newCol;
                            DSU.Union(index,newIndex);
                        }
                        
                    }
                }
            }
        }

        return DSU.getMaxSizeNumber();
    }
};