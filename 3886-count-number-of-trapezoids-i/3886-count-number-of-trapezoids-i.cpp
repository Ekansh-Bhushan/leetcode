class Solution {
    typedef pair<int, int> P;
    const int MOD = 1e9+7;
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();

        unordered_map<int, int> countTheYPoints;

        for (int i = 0 ; i < n ; i++)
            countTheYPoints[points[i][1]]++;

        vector<long long> numberOfLinesSegemnts;
        for (auto& [y, count] : countTheYPoints) {
            if (count >= 2) {
                numberOfLinesSegemnts.push_back(1LL * count * (count - 1) / 2);
            }
        }

        long long cnt = 0, prefixSum = 0;
        for (long long linesSegemnts : numberOfLinesSegemnts) {
            cnt = (cnt + linesSegemnts * prefixSum % MOD) % MOD;
            prefixSum = (prefixSum + linesSegemnts) % MOD;
        }

        return cnt;
    }
};