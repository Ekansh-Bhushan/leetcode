class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        vector<int> total(k, 0);  // Track total requests handled by each server
        set<int> st;              // Available servers
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // Min-heap to track server end times
        
        // Initialize available servers
        for (int i = 0; i < k; i++) {
            st.insert(i);
        }
        
        // Process each request
        for (int i = 0; i < n; i++) {
            int start = arrival[i];     // Arrival time of current request
            int diff = load[i];         // Processing time of current request
            int end = start + diff;     // End time of current request
            
            // Check servers in the priority queue
            while (!pq.empty()) {
                auto it = pq.top();
                if (it.first <= start) {
                    st.insert(it.second); // Server becomes available
                    pq.pop();
                } else {
                    break;
                }
            }
            
            // If no servers available, skip current request
            if (st.empty()) {
                continue;
            }
            
            // Find an available server using modulo operation
            auto it = st.lower_bound(i % k);
            if (it != st.end()) {
                total[*it]++;         // Increment request count for chosen server
                pq.push({end, *it});  // Push end time of current request to priority queue
                st.erase(it);         // Remove chosen server from available set
            } else {
                auto first = st.begin();
                total[*first]++;      // Increment request count for the first available server
                pq.push({end, *first}); // Push end time of current request to priority queue
                st.erase(first);      // Remove first server from available set
            }
        }
        
        // Determine servers with maximum requests handled
        vector<int> ans;
        int mx = 0;
        for (int i = 0; i < total.size(); i++) {
            mx = max(mx, total[i]); // Find maximum requests handled by any server
        }
        for (int i = 0; i < total.size(); i++) {
            if (total[i] == mx) {
                ans.push_back(i);   // Collect servers with maximum requests handled
            }
        }
        
        return ans;  // Return indices of busiest servers
    }
};