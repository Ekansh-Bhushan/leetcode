class Solution {
    struct TrieNode {
        TrieNode* links[26] = {nullptr};
        string word = "";
    };

    TrieNode* root;
    int n, m;
    vector<string> ans;

    void insertWord(string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->links[idx]) node->links[idx] = new TrieNode();
            node = node->links[idx];
        }
        node->word = word;  // mark end of word
    }

    void dfs(int row, int col, vector<vector<char>>& board, TrieNode* node) {
        char ch = board[row][col];
        if (ch == '#' || !node->links[ch - 'a']) return;

        node = node->links[ch - 'a'];
        if (!node->word.empty()) {
            ans.push_back(node->word);
            node->word = "";  // avoid duplicate insertions
        }

        board[row][col] = '#'; // mark visited

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                dfs(newRow, newCol, board, node);
            }
        }

        board[row][col] = ch; // backtrack
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        n = board.size();
        m = board[0].size();

        // Build Trie
        for (auto& word : words) {
            insertWord(word);
        }

        // DFS from each cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(i, j, board, root);
            }
        }

        return ans;
    }
};
