class Solution {
    int getNcR(int n , int r) {
        long long res = 1;
        for(int i = 0 ; i < r ; i++) {
            res = res * (n-i);
            res = res / (i+1);
        }
        return res;
    }
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        int row = rowIndex + 1;
        for(int i = 1 ; i <= row; i++) {
            ans.push_back(getNcR(row-1,i-1));
        }
        return ans;
    }
};