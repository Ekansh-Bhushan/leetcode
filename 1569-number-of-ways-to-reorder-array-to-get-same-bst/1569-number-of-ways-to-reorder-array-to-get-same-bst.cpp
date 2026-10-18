class Solution {
public:

    typedef long long ll;
    const ll MOD = 1e9+7;
    vector<vector<ll>> pascalTriangle;

    int n;

    int solve(vector<int>& nums) {

        int m = nums.size();
        if(m < 3) {
            return 1;
        }

        int root = nums[0];

        vector<int> leftArray, rightArray;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < root) {
                leftArray.push_back(nums[i]);
            } else {
                rightArray.push_back(nums[i]);
            }
        }

        ll x = (solve(leftArray)) % MOD;
        ll y = (solve(rightArray)) % MOD;

        // n-1 C leftArray.size();

        ll z = pascalTriangle[m-1][leftArray.size()];

        ll temp = (x * y) % MOD;
        return (z * temp) % MOD;
    }
    int numOfWays(vector<int>& nums) {
        n = nums.size();

        pascalTriangle.resize(n+1);

        for(int i = 0; i <= n ; i++) {
            pascalTriangle[i] = vector<ll>(i + 1, 1);

            for(int j = 1; j < i ; j++) {
                pascalTriangle[i][j] = (pascalTriangle[i-1][j-1] + pascalTriangle[i-1][j] ) % MOD;
            }
        }

        return (solve(nums) - 1) % MOD;
    }
};