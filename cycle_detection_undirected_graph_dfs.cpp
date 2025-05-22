#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], vector<bool>& visited) {
    visited[node] = true;
    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            if (dfs(neigh, node, adj, visited)) return true;
        } else if (neigh != parent) {
            return true;
        }
    }
    return false;
}

bool hasCycleDFS(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) return true;
        }
    }
    return false;
}

// Time Complexity: O(V + E)
// Space Complexity: O(V)
