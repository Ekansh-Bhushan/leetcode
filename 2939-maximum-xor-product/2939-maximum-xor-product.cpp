class Solution {
    const int MOD = 1e9+7;
    typedef long long ll;
public:
    int maximumXorProduct(long long a, long long b, int n) {
        ll aXorx = 0;
        ll bXorx = 0;

        //49th to nth bit same
        for(int i = 49; i >= n; i--) {
            bool a_ith_bit = ((a >> i) & 1) > 0;
            bool b_ith_bit = ((b >> i) & 1) > 0;
            if(a_ith_bit) {
                aXorx = aXorx ^ (1ll << i);
            }
            if(b_ith_bit) {
                bXorx = bXorx ^ (1ll << i);
            }
        }

        for(ll i = n-1; i>= 0; i--) {
            bool a_ith_bit = ((a >> i) & 1) > 0;
            bool b_ith_bit = ((b >> i) & 1) > 0;

            if(a_ith_bit == b_ith_bit) {
                aXorx = aXorx ^ (1ll << i);
                bXorx = bXorx ^ (1ll << i);
                continue;
            }

            if(aXorx > bXorx){
                bXorx = bXorx ^ (1ll << i);
            } else {
                aXorx = aXorx ^ (1ll << i);
            }
        }

        aXorx = aXorx%MOD;
        bXorx = bXorx%MOD;

        return (aXorx * bXorx) % MOD;
    }
};