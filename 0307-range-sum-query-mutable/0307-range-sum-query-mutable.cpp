class SegmentTree{
    vector<int> nums;
    public:
        vector<int> segTree;
        SegmentTree(vector<int>& arr){
            int n = arr.size();
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

        void update(int idx, int val, int i , int l , int r) {
            if(l == r) {
                segTree[i] = val;
                return;
            }

            int mid = (l+r)/2;
            if(idx <= mid)
                update(idx,val,2*i+1, l , mid);
            else
                update(idx,val,2*i+2, mid+1 , r);
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
    SegmentTree segTree;
    int n;
public:
    NumArray(vector<int>& nums) : segTree(nums){
        n = nums.size();
        segTree.buildTree(0,0,n-1);
    }
    
    void update(int index, int val) {
        segTree.update(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return segTree.query(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */