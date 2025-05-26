#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Since it's an undirected graph
    }
/**********************************************************************************************************************************************************/

    // DFS approach
    bool isBipartiteDFSUtil(int v, vector<int>& color, int c) {
        color[v] = c;

        for (int neighbor : adj[v]) {
            if (color[neighbor] == -1) {
                if (!isBipartiteDFSUtil(neighbor, color, 1 - c))
                    return false;
            } else if (color[neighbor] == color[v]) {
                return false;
            }
        }
        return true;
    }

    bool isBipartiteDFS() {
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!isBipartiteDFSUtil(i, color, 0))
                    return false;
            }
        }
        return true;
    }
/**********************************************************************************************************************************/

    // BFS approach
    bool isBipartiteBFS() {
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : adj[node]) {
                        if (color[neighbor] == -1) {
                            color[neighbor] = 1 - color[node];
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

/*******************************************************************************************************************************************/

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(4, 5);

    cout << "Using DFS: " << (g.isBipartiteDFS() ? "Graph is Bipartite" : "Graph is Not Bipartite") << endl;
    cout << "Using BFS: " << (g.isBipartiteBFS() ? "Graph is Bipartite" : "Graph is Not Bipartite") << endl;

    return 0;
}
