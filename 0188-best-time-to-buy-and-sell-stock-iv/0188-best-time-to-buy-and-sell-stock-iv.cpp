class Solution {
    int n;
public:
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();


        vector<vector<int>> ahead(2, vector<int> (k+1,0));
        vector<vector<int>> curr(2, vector<int> (k+1,0));

        for(int i = n-1 ; i>=0 ; i--) {
            for(int buy = 0; buy < 2 ; buy++) {
                for(int trancation = 0 ; trancation < k ; trancation++) {
                    if(buy == 1) {
                        curr[buy][trancation] = max(-prices[i] + ahead[0][trancation], ahead[1][trancation]);
                    } else {
                        curr[buy][trancation] = max(prices[i] + ahead[1][trancation+1], ahead[0][trancation]);
                    }
                    ahead =curr;
                }
            }
        }

        return ahead[1][0];
    }
};