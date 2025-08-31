class Solution {
    typedef pair<int,int> P;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<P,vector<P>,greater<P>> pq;
        unordered_map<int,int> mpp;

        for(auto num : nums){
            mpp[num]++;
        }
        vector<int> ans;

        for(auto it :mpp) {
            pq.push({it.second,it.first});

            if(pq.size() > k) {
                pq.pop();
            }
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};