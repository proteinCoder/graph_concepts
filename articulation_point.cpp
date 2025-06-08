class Solution {
  public:
    int timer;
    vector<int> disc, low;
    vector<bool> visited;
    vector<bool> isArticulation;

    void dfs(int u, int parent, vector<int> adj[]) {
        visited[u] = true;
        disc[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;

            if(visited[v]){
                // Back edge
                low[u] = min(low[u], disc[v]);
            }
            else{
                children++;
                dfs(v, u, adj);
                low[u] = min(low[u], low[v]);

                // Case 1: u is not root and low[v] >= disc[u]
                if (parent != -1 && low[v] >= disc[u]) {
                    isArticulation[u] = true;
                }
            } 
        }

        // Case 2: u is root and has more than 1 child
        if (parent == -1 && children > 1) {
            isArticulation[u] = true;
        }
    }

    vector<int> articulationPoints(int V, vector<int> adj[]) {
        timer = 0;
        disc.assign(V, -1);
        low.assign(V, -1);
        visited.assign(V, false);
        isArticulation.assign(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, -1, adj);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; ++i) {
            if (isArticulation[i]) {
                result.push_back(i);
            }
        }

        if (result.empty()) return {-1};
        return result;
    }
};
