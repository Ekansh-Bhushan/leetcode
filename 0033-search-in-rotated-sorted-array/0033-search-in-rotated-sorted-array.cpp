class Solution {
public:
    int search(vector<int>& arr, int target) {
        int l = 0 , r = arr.size() - 1 ;
        while( r >= l ) {
            int mid = l + (r-l)/2;
            if (arr[mid] == target) return mid;
            //left sorted
            if(arr[l] <= arr[mid]){
                if(arr[l] <= target && target <= arr[mid]){
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if(arr[r] >= target && target >= arr[mid]){
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};