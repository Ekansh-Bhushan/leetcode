class Disjoint{
public:
    vector<int> parent;
    vector<int> rank;

    Disjoint(int n) {
        parent.resize(n+1);
        rank.resize(n+1,0);

        for(int i = 0; i <= n ; i++) {
            parent[i] = i;
        }
    }

    int findParent(int x) {
        if(x == parent[x]) return x;
        return parent[x] = findParent(parent[x]);
    }

    void Union(int x, int y) {
        int xParent = findParent(x);
        int yParent = findParent(y);

        if(xParent == yParent) return;

        if(rank[xParent] > rank[yParent]) {
            parent[yParent] = xParent;
        } else if(rank[xParent] < rank[yParent]) {
            parent[xParent] = yParent;
        } else {
            parent[xParent] = yParent;
            rank[yParent]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        Disjoint DSU(n);

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if(DSU.findParent(u) == DSU.findParent(v)){
                return {u,v};
            }

            DSU.Union(u,v);
        }

        return {};
    }
};