class Solution {
    int n;
    int transcationFee;
public:
    int maxProfit(vector<int>& prices,int fee) {
        n = prices.size();
        transcationFee = fee;

        int aheadCanBuy = 0, aheadCanNotBuy = 0;
        int currCanBuy, currCanNotBuy;

        for(int i = n-1 ; i >= 0 ; i--) {
            currCanBuy = max(-prices[i] + aheadCanNotBuy,aheadCanBuy);    
            currCanNotBuy = max(prices[i] + aheadCanBuy- transcationFee,aheadCanNotBuy);
    
            aheadCanBuy = currCanBuy;
            aheadCanNotBuy =currCanNotBuy;
        }

        return aheadCanBuy;
    }
};