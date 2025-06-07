class Solution {
public:
    int timer = 0;
    vector<int> disc, low;
    vector<bool> visited;
    vector<vector<int>> bridges;

    void dfs(int u, int parent, vector<vector<int>>& adj) {
        visited[u] = true;
        disc[u] = low[u] = timer++;
        for (int v : adj[u]) {
            if (v == parent)
                continue;
            if (!visited[v]) {
                dfs(v, u, adj);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    bridges.push_back({u, v});
                }
            } else {
                low[u] = min(low[u], disc[v]); // back edge
            }
        }
    }
    vector<vector<int>> criticalConnections(int V, vector<vector<int>>& conn) {

        vector<vector<int>> adj(V);
        for (auto& it : conn) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        disc.assign(V, -1);
        low.assign(V, -1);
        visited.assign(V, false);
        bridges.clear();
        for (int i = 0; i < V; ++i) {
            if (!visited[i])
                dfs(i, -1, adj);
        }
        return bridges;
    }
};
