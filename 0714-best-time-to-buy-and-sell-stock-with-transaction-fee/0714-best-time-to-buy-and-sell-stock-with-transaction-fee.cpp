class Solution {
    int n;
public:
    int maxProfit(vector<int>& prices,int fee) {
        n = prices.size();
        vector<int> ahead(2,0), curr(2,0);

        ahead[0] = 0;
        ahead[1] = 0;

        for(int i = n-1 ; i >= 0 ; i--) {
            for(int buy = 0; buy < 2 ; buy++) {
                if(buy) {
                    curr[buy] = max(-prices[i] + ahead[!buy], ahead[buy]);
                } else {
                    curr[buy] = max(prices[i] + ahead[!buy] - fee, ahead[buy]);
                }
            }
            ahead = curr;
        }
        return ahead[1];
    }
};