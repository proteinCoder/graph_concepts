#include <vector>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    const int INF = 1e8;
    vector<int> dist(V, INF);
    dist[src] = 0;

    // Bellman-Ford main loop with early stopping
    for (int i = 0; i < V - 1; i++) {
        bool updated = false;
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            if (dist[u] != INF && dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
                updated = true;
            }
        }
        if (!updated) break;  // No updates => optimal distances found
    }

    // Check for negative weight cycles
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1], wt = edge[2];
        if (dist[u] != INF && dist[v] > dist[u] + wt) {
            return {-1};  // Negative cycle detected
        }
    }

    return dist;
}
