class SegmentTree{
    vector<int> nums;
    public:
        int n;
        vector<int> segTree;
        SegmentTree(vector<int>& arr){
            n = arr.size();
            nums = arr;
            segTree.resize(4*n);
        }

        void buildTree(int i , int l, int r){
            if(l == r) {
                segTree[i] = nums[l];
                return;
            }

            int mid = (l+r)/2;
            buildTree(2*i+1, l, mid);
            buildTree(2*i+2, mid+1, r);

            segTree[i] = segTree[2*i+1] + segTree[2*i+2];
        }

        int query(int start, int end, int i , int l, int r){
            if(l > end || r < start){
                return 0;
            }

            if(start <= l && end >= r) {
                return segTree[i];
            }

            int mid = (l+r)/2;
            return query(start,end,2*i+1 , l, mid) + query(start,end,2*i+2 , mid+1, r);
        }
};

class NumArray {
    int n;
    SegmentTree segmentTree;
public:
    NumArray(vector<int>& nums) : segmentTree(nums)  {
        n = nums.size();
        segmentTree.buildTree(0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return segmentTree.query(left,right,0,0,n-1);
    }
};