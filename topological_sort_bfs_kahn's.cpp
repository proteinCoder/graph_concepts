#include <bits/stdc++.h>
using namespace std;

vector<int> kahnTopoSort(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    vector<int> topo;

    // Step 1: Compute indegree
    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    // Step 2: Push nodes with 0 indegree to queue
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0)
            q.push(i);
    }

    // Step 3: Process the queue
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    // Optional: Check for cycle
    if (topo.size() < n) {
        cout << "Graph has a cycle. Topo sort not possible." << endl;
        return {};
    }

    return topo;
}
