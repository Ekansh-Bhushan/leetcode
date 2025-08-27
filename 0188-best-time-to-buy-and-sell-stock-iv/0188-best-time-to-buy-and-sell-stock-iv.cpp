class Solution {
    int n;
public:
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        if (n == 0 || k == 0) return 0;

        vector<int> ahead(2*k+1, 0);
        vector<int> curr(2*k+1, 0);

        for (int i = n-1; i >= 0; i--) {
            for (int transaction = 0; transaction < 2*k; transaction++) {
                if (transaction % 2 == 0) {
                    curr[transaction] = max(-prices[i] + ahead[transaction+1],ahead[transaction]);
                } else {
                    curr[transaction] = max(prices[i] + ahead[transaction+1],ahead[transaction]);
                }
                ahead = curr;
            }
        }

        return ahead[0];
    }
};
