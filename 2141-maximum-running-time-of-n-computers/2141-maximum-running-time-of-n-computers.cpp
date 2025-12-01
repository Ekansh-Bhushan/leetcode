class Solution {
    bool possible(vector<int>& batteries, long long mid_mins, int n) {
        long long target_min = n*mid_mins;

        long long sum = 0;

        for(auto minuts : batteries){
            sum += min(mid_mins, (long long)minuts);
            if(sum >= target_min) {
                return true;
            }
        }
        return false;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l = *min_element(batteries.begin(),batteries.end());
        long long total_mins = 0;

        for(auto min : batteries){
            total_mins += min;
        }

        long long r = total_mins/n;
        long long result = 0;
        while(l <= r) {
            long long mid_min = l + (r-l)/2;

            if(possible(batteries,mid_min,n)) {
                result = mid_min;
                l = mid_min + 1;
            } else {
                r = mid_min - 1;
            }
        }

        return result;
    }
};