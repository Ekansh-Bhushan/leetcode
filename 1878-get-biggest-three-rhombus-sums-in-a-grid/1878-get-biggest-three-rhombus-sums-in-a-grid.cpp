class Solution {
    set<int> st;

    void addToSetAndCheck(int n) {
        st.insert(n);
        if(st.size() > 3) {
            st.erase(st.begin());
        }
    }
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int row = 0; row < n ; row++){
            for(int col = 0; col < m; col++) {

                addToSetAndCheck(grid[row][col]);

                for(int side = 1 ; row - side >= 0 && row + side < n && col - side >= 0 && col + side < m ; side++) {
                    int sum = 0;
                    for(int k = 0 ;k <= side - 1; k++) {
                        sum += grid[row-side+k][col+k];
                        sum += grid[row+k][col+side-k];
                        sum += grid[row+side-k][col-k];
                        sum += grid[row-k][col-side+k];
                    }

                    addToSetAndCheck(sum);
                }
            }
        }

        return vector<int>(st.rbegin(),st.rend());
    }
};