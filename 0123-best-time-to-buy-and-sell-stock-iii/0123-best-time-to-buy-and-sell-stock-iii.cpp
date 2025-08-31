class Solution {
    int n;
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();


        vector<vector<int>> ahead(2, vector<int> (3,0)), curr(2, vector<int> (3,0));
        for(int i = n-1 ; i >= 0 ; i--) {
            for(int buy = 0 ; buy < 2 ; buy++) {
                for(int transaction = 1; transaction < 3 ;transaction++) {
                    if(buy == 1) {
                        curr[buy][transaction] = max(-prices[i] + ahead[0][transaction], ahead[1][transaction]);
                    } else {
                        curr[buy][transaction] = max(prices[i] + ahead[1][transaction-1], ahead[0][transaction]);
                    }
                }
                ahead = curr;
            }
        }
        

        return  ahead[1][2];
    }
};