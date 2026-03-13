class Solution {
    typedef long long ll;

    bool isPossible(int mountainHeight,ll minTime, vector<int>& workerTimes) {
        ll h = 0;
        for(auto time : workerTimes) {
            h += (ll)(sqrt((2.0 * minTime / time) + 0.25) - 0.5);

            if(h >= mountainHeight) {
                return true;
            }
        }

        return h >= mountainHeight;
    }

public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll tMax = *max_element(workerTimes.begin(), workerTimes.end());
        ll l = 1;
        ll r = (ll)tMax * ((ll)mountainHeight * (mountainHeight + 1) / 2);
        ll res = INT_MAX;

        while(l <= r) {
            ll mid = l + (r - l) / 2;

            if(isPossible(mountainHeight, mid, workerTimes)){
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};