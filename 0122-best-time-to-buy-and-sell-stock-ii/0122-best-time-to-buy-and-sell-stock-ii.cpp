class Solution {
    int n;
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();

        vector<int> ahead(2,0), curr(2,0);

        for(int i = n-1 ; i >= 0 ; i--) {
            for(int buy = 0 ; buy < 2; buy++){
                int profit = 0;
                if(buy) {
                    profit = max(-prices[i] + ahead[0], ahead[1]);
                } else {
                    profit = max(prices[i] + ahead[1], ahead[0]);
                }

                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};