#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(int start, vector<int> adj[], vector<bool>& visited) {
    queue<pair<int, int>> q;
    q.push({start, -1});
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                visited[neigh] = true;
                q.push({neigh, node});
            } else if (neigh != parent) {
                return true;
            }
        }
    }
    return false;
}

bool hasCycleBFS(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (bfs(i, adj, visited)) return true;
        }
    }
    return false;
}

// Time Complexity: O(V + E)
// Space Complexity: O(V)
