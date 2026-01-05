class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long n = matrix.size();
        long long cntPos = 0;
        long long PosSum = 0;
        long long NegSum = 0;
        long long minEleNeg = INT_MIN;
        long long minElePos = INT_MAX;
        long long cntNeg = 0;

        for(int i = 0; i < n ;i++) {
            for(int j = 0; j < n; j++) {
                long long ele = matrix[i][j];
                if(ele <= 0) {
                    minEleNeg = max(minEleNeg,ele);
                    cntNeg++;
                    NegSum += ele;
                } else {
                    minElePos = min(minElePos,ele);
                    cntPos++;
                    PosSum += ele;
                }
            }
        }

        

        long long totalSum = PosSum + abs(NegSum);
        if(cntNeg % 2 != 0) {
            if(abs(minElePos) < abs(minEleNeg)) return totalSum - 2*abs(minElePos);
            return totalSum - 2*abs(minEleNeg);
        }
        return totalSum;
    }
};