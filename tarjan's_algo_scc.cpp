// User function template for C++

class Solution {
  public:
    int timer;
    vector<int> disc, low;
    vector<bool> inStack;
    stack<int> st;
    vector<vector<int>> sccs;

    void dfs(int u, vector<int> adj[]) {
        disc[u] = low[u] = timer++;
        st.push(u);
        inStack[u] = true;

        for (int v : adj[u]) {
            if (disc[v] == -1) {
                dfs(v, adj);
                low[u] = min(low[u], low[v]);
            } else if (inStack[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }

        // Found head of a strongly connected component
        if (low[u] == disc[u]) {
            vector<int> component;
            while (true) {
                int v = st.top(); st.pop();
                inStack[v] = false;
                component.push_back(v);
                if (v == u) break;
            }
            sort(component.begin(), component.end());
            sccs.push_back(component);
        }
    }

    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        disc.assign(V, -1);
        low.assign(V, -1);
        inStack.assign(V, false);
        timer = 0;

        for (int i = 0; i < V; ++i) {
            if (disc[i] == -1) {
                dfs(i, adj);
            }
        }

        sort(sccs.begin(), sccs.end());
        return sccs;
    }
};
