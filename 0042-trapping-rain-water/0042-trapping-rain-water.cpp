class Solution {
    int n;
    vector<int> leftMaxCalculation(vector<int>& height) {
        vector<int> left(n);
        left[0] = height[0];
        for(int i =1 ; i < n ;i++) {
            left[i] = max(left[i-1],height[i]);
        }
        return left;
    }

    vector<int> rightMaxCalculation(vector<int>& height) {
        vector<int> right(n);
        right[n-1] = height[n-1];
        for(int i = n-2 ; i >= 0 ; i--) {
            right[i] = max(right[i+1],height[i]);
        }
        return right;
    }
public:
    int trap(vector<int>& height) {
        n = height.size();
        int total = 0 ;
        vector<int> leftMax = leftMaxCalculation(height);
        vector<int> rightMax = rightMaxCalculation(height);
        for(int i= 0 ; i < n ; i++) {
            if(height[i] < leftMax[i] && height[i] < rightMax[i]) {
                total += min(leftMax[i],rightMax[i]) - height[i];
            }
        }
        return total;
    }
};