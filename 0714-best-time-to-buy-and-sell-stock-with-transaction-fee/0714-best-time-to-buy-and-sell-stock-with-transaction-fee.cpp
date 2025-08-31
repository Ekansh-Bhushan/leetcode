class Solution {
    int n;
    int transcationFee;
public:
    int maxProfit(vector<int>& prices,int fee) {
        n = prices.size();
        transcationFee = fee;
        vector<int> ahead(2,0), curr(2,0);

        for(int i = n-1 ; i >= 0 ; i--) {
            curr[1] = max(-prices[i] + ahead[0],ahead[1]);    
            curr[0] = max(prices[i] + ahead[1]- transcationFee,ahead[0]);
    
            ahead = curr;
        }

        return ahead[1];
    }
};