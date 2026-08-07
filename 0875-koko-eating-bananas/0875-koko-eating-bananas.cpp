class Solution {
    long long reqHours(vector<int>& piles, int k) {
        long long hours = 0;

        for(int i = 0 ; i < piles.size() ; i++) {
            hours += (long long)(piles[i] + k - 1) / k;
        }
        return hours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while(l <= r) {
            int mid = (l+r)/2;

            long long totalHours = reqHours(piles,mid);

            if(totalHours <= h) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
