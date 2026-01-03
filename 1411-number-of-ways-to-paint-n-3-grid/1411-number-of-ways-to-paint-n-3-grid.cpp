class Solution {
    // m = row      n = col
    vector<string> columnStates;

    int row, col;
    const int MOD = 1e9+7;


    void generateStates(string currState, int len, char prevColor) {
        if(len == row) {
            columnStates.push_back(currState);
            return;
        }

        for(char ch : {'R','G','B'}) {
            if(ch == prevColor) {
                continue;
            }
            generateStates(currState + ch, len+1, ch);
        }
    }

    int solve(int prevStateIdx, int remainingCols, vector<vector<int>>& dp) {
        if(remainingCols == 0){
            return 1;
        }

        if(dp[remainingCols][prevStateIdx] != -1) return dp[remainingCols][prevStateIdx];
        
        int ways = 0;

        string prevState = columnStates[prevStateIdx];
        for(int i = 0; i < columnStates.size(); i++) {
            if(i == prevStateIdx) continue;

            string currState = columnStates[i];
            bool valid = true;

            for(int j = 0; j < row; j++) {
                if(prevState[j] == currState[j]) {
                    valid = false;
                    break;
                }
            }

            if(valid){
                ways = (ways + solve(i,remainingCols-1,dp)) % MOD;
            }
        }

        return dp[remainingCols][prevStateIdx] = ways;
    }

    int colorTheGrid(int m, int n) {

        row = m;
        col = n;
        generateStates("",0,'#');

        int totalStates = columnStates.size();
        vector<vector<int>> dp(n+1, vector<int> (totalStates+1,-1));

        int result = 0;
        for(int i= 0; i < columnStates.size();i++){
            result = (result+solve(i,n-1,dp))%MOD;
        }

        return result;
    }
public:
    int numOfWays(int n) {
        return colorTheGrid(3,n);
    }
};