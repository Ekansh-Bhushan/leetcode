class Solution {
    int n;
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> ahead(5,0);
        vector<int> curr(5,0);

        for(int i = n-1; i >= 0; i--) {
            for(int tranction = 0; tranction < 4; tranction++) {
                if(tranction % 2 == 0) { 
                   curr[tranction] = max(-prices[i] + ahead[tranction+1], ahead[tranction]);
                } else { 
                    curr[tranction] = max(prices[i] + ahead[tranction+1], ahead[tranction]);
                }
                ahead = curr;
            }
        }
        return ahead[0];
    }
};