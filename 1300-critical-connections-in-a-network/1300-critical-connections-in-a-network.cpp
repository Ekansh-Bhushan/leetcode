class Solution {
    int timer = 1;

    void dfs(int node, int parent, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& tm, vector<int>& low,
             vector<vector<int>>& bridges) {

        vis[node] = 1;
        tm[node] = low[node] = timer++;
        
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (!vis[it]) {
                dfs(it, node, adj, vis, tm, low, bridges);
                low[node] = min(low[node], low[it]);

                if (low[it] > tm[node]) {
                    bridges.push_back({node, it});
                }
            } else {
                low[node] = min(low[node], tm[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto& edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, 0), tm(n), low(n);
        vector<vector<int>> bridges;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, vis, tm, low, bridges);
            }
        }
        return bridges;
    }
};
