class Solution {

    int findDayOfYear(string date, vector<int>& preSum) {
        int month = stoi(date.substr(0,2));
        int days = stoi(date.substr(3));

        return preSum[month - 1] + days;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> monthDay = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        vector<int> preSum(13,0);

        preSum[1] = monthDay[0];

        for(int i = 2; i <= 12 ;i++) {
            preSum[i] = preSum[i-1] + monthDay[i-1];
        }

        int arriveAliceDay = findDayOfYear(arriveAlice, preSum);
        int leaveAliceDay = findDayOfYear(leaveAlice, preSum);
        int arriveBobDay = findDayOfYear(arriveBob, preSum);
        int leaveBobDay = findDayOfYear(leaveBob, preSum);

        int overLapDay = min(leaveBobDay, leaveAliceDay) - max(arriveAliceDay, arriveBobDay) + 1;
        return overLapDay < 0 ? 0 : overLapDay;
    }
};