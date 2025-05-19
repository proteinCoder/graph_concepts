#include <bits/stdc++.h>
using namespace std;

/*********************************************************************************************************/

void bfs(int start, vector<int> adj[], vector<bool>& visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";  // Process the node

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

/*************************************************************************************************************/
int main() {
    int n, m; // n = number of nodes, m = number of edges
    cin >> n >> m;

    vector<int> adj[n + 1]; // 1-based indexing

    // Build the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Remove this line for a directed graph
    }

    vector<bool> visited(n + 1, false);

    // Call BFS for each connected component
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "BFS from node " << i << ": ";
            bfs(i, adj, visited);
            cout << endl;
        }
    }

    return 0;
}
