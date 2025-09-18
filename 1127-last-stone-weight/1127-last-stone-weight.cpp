class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(auto stone : stones) {
            pq.push(stone);
        }

        while(pq.size() > 1) {
            int stoneOne = pq.top();
            pq.pop();
            int stoneTwo = pq.top();
            pq.pop();

            int result = abs(stoneOne - stoneTwo);

            if(result > 0) {
                pq.push(result);
            }
        }

        if(pq.empty()) {
            return 0;
        } else {
            return pq.top();
        }
    }
};