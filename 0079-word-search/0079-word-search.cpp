class Solution {
    int n ,m;
    bool dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis, string& word, int index) {
        if(index == word.length()) return true;

        vis[row][col] = 1;

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,-1,0,1};

        for(int i=0 ; i < 4 ; i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];
            
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && board[newRow][newCol] == word[index] && !vis[newRow][newCol]){
                if(dfs(newRow,newCol,board,vis,word,index+1)) return true;
            }
        }

        vis[row][col] = 0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        int index = 0;
        vector<vector<int>> vis(n, vector<int> (m,0));

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(board[i][j] == word[index] && !vis[i][j]) {
                    if(dfs(i,j,board,vis,word,index+1)) return true;
                }
            }
        }
        return false;
    }
};