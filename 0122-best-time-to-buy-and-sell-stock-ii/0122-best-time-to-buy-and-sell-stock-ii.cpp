class Solution {
    int n;
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();

        int aheadNotBuy = 0;
        int aheadBuy = 0;
        int currNotBuy, currBuy;

        for(int i = n-1 ; i >= 0 ; i--) {
           
            currBuy = max(-prices[i] + aheadNotBuy, aheadBuy);
                
            currNotBuy = max(prices[i] + aheadBuy, aheadNotBuy);
                

                
            aheadNotBuy = currNotBuy;
            aheadBuy = currBuy;
        }
        return aheadBuy;
    }
};