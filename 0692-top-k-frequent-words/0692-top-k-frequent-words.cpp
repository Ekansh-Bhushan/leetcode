class Solution {
    typedef pair<string, int> P;
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mpp;
        for (string& word : words) {
            mpp[word]++;
        }

        auto cmp = [](const P &a, const P &b) {
            if (a.second == b.second)
                return a.first > b.first; // lexicographically greater goes lower
            return a.second < b.second; // lower freq goes lower
        };

        priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);

        for (auto& it : mpp) {
            pq.push({it.first, it.second});
        }

        vector<string> res;
        for (int i = 0; i < k && !pq.empty(); i++) {
            res.push_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};
