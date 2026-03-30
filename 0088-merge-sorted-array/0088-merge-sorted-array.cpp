class Solution {
    // Helper to swap across the two vectors
    void swapIfGreater(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if (nums1[i] > nums2[j]) {
            swap(nums1[i], nums2[j]);
        }
    }

    // Helper to swap within the same vector (specifically for nums2)
    void swapInternal(vector<int>& nums, int i, int j) {
        if (nums[i] > nums[j]) {
            swap(nums[i], nums[j]);
        }
    }

public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m + n;
        if (n == 0) return; // Nothing to merge

        int gap = (len / 2) + (len % 2);

        while (gap > 0) {
            int left = 0;
            int right = left + gap;

            while (right < len) {
                // Case 1: Both pointers in nums1
                if (left < m && right < m) {
                    if (nums1[left] > nums1[right]) swap(nums1[left], nums1[right]);
                } 
                // Case 2: Left in nums1, Right in nums2
                else if (left < m && right >= m) {
                    swapIfGreater(nums1, nums2, left, right - m);
                } 
                // Case 3: Both pointers in nums2
                else {
                    swapInternal(nums2, left - m, right - m);
                }
                left++;
                right++;
            }

            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }

        // Final step: Copy nums2 into the back of nums1
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};