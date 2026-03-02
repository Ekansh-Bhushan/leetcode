class Solution {
    int n;
    int solve(int i, vector<int>& days, vector<int>& costs,vector<int>& dp) {

        if(i >= n){
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        // 1 day pass
        int costForOneDayPass = costs[0] + solve(i + 1, days, costs,dp);

        // 7 day pass
        int maxDayFor7 = days[i] + 7;
        int j = i;
        while(j < n && days[j] < maxDayFor7){
            j++;
        }
        int costForSevenDayPass = costs[1] + solve(j,days,costs,dp);

        // 30 days pass
        int maxDayFor30 = days[i] + 30;
        int k = i;
        while(k < n && days[k] < maxDayFor30){
            k++;
        }
        int costForThirtyDayPass = costs[2] + solve(k,days,costs,dp);

        return dp[i] = min(costForOneDayPass, min(costForSevenDayPass, costForThirtyDayPass));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        vector<int> dp(n+1, -1);
        return solve(0, days, costs, dp);
    }
};