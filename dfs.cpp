#include <bits/stdc++.h>
using namespace std;

/*******************************************************************************************************************/

void dfs(int node, vector<int> adj[], vector<bool>& visited) {
    // Mark the current node as visited
    visited[node] = true;
    cout << node << " ";  // Process the node (can be modified as needed)

    // Recur for all the adjacent nodes
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}


/*********************************************************************************************************************/
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

    // Call DFS for each connected component
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "DFS from node " << i << ": ";
            dfs(i, adj, visited);
            cout << endl;
        }
    }

    return 0;
}
