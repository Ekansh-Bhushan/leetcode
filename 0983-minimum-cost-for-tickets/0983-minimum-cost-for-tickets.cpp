class Solution {
    int n;
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        vector<int> dp(n+1, 0);

        for(int i = n-1; i >= 0; i--) {

            // 1 day pass
            int costForOneDayPass = costs[0] + dp[i + 1];

            // 7 days pass
            int maxDayFor7 = days[i] + 7;
            int j = i;
            while(j < n && days[j] < maxDayFor7){
                j++;
            }
            int costForSevenDayPass = costs[1] + dp[j];

            // 30 days pass
            int maxDayFor30 = days[i] + 30;
            int k = i;
            while(k < n && days[k] < maxDayFor30){
                k++;
            }
            int costForThirtyDayPass = costs[2] + dp[k];

            dp[i] = min(costForOneDayPass, min(costForSevenDayPass, costForThirtyDayPass));
        }
        return dp[0];
    }
};