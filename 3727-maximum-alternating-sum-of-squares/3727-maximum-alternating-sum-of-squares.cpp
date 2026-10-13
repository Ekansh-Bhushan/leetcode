class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares(n);
        
        // Square elements using long long to prevent overflow
        for (int i = 0; i < n; i++) {
            squares[i] = (long long)nums[i] * nums[i];
        }

        // Sort ascending: smallest squares will be at the beginning
        sort(squares.begin(), squares.end());

        long long score = 0;
        int negativeCount = n / 2; // Number of minus slots

        for (int i = 0; i < n; i++) {
            if (i < negativeCount) {
                score -= squares[i]; // Subtract smallest squares
            } else {
                score += squares[i]; // Add remaining larger squares
            }
        }

        return score;
    }
};