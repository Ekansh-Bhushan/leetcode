class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            // Else the minimum is in the left half (including mid)
            else {
                high = mid;
            }
        }

        return nums[low]; // low is the index of the smallest element
    }
};
