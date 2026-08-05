class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for(auto& it : adj[node]) {
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        vector<vector<int>> adj(n);

        for(auto& it : invocations) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        vector<int> vis(n, 0);

        dfs(k,adj,vis);

        vector<int> ans;

        for(auto& it : invocations) {
            int u = it[0];
            int v = it[1];

            if (!vis[u] && vis[v]) {
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};