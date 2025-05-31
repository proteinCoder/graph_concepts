vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V, 1e8);
        dist[src] = 0;
    
        // Relax all edges (V - 1) times
        for (int i = 0; i < V - 1; i++) {
            for (auto &edge : edges) {
                int u = edge[0], v = edge[1], wt = edge[2];
                if (dist[u] != 1e8 && dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
    
        // Check for negative weight cycles
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            if (dist[u] != 1e8 && dist[v] > dist[u] + wt) {
                // Negative cycle detected
                return {-1};
            }
        }
    
        return dist;
    }
