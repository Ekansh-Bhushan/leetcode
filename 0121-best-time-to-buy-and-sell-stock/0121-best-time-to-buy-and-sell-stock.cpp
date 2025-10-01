class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = prices[0];
        int profit = 0;
        int n = prices.size();

        for(int i = 1 ; i< n ; i++ ){
            int sellingPrice = prices[i] - cost;
            profit = max(sellingPrice,profit);
            cost = min(cost, prices[i]);
        }

        return profit;
    }
};