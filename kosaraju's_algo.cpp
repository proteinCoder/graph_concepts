//Position this line where user code will be pasted.
class Solution {
  public:
    void getOrder(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v])
                getOrder(v, adj, visited, st);
        }
        st.push(u);
    }

    void dfs(int u, vector<vector<int>>& rev_adj, vector<bool>& visited) {
        visited[u] = true;
        for (int v : rev_adj[u]) {
            if (!visited[v])
                dfs(v, rev_adj, visited);
        }
    }
    
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int  V=adj.size();
        vector<bool> visited(V, false);
        stack<int> st;

        // 1. Fill vertices in stack according to their finishing times
        for (int i = 0; i < V; ++i) {
            if (!visited[i])
                getOrder(i, adj, visited, st);
        }

        // 2. Transpose the graph
        vector<vector<int>> rev_adj(V);
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                rev_adj[v].push_back(u);
            }
        }

        // 3. Do DFS based on finishing time in decreasing order
        fill(visited.begin(), visited.end(), false);
        int sccs = 0;

        while (!st.empty()) {
            int u = st.top();
            st.pop();
            if (!visited[u]) {
                dfs(u, rev_adj, visited);
                sccs++;  // One new SCC found
            }
        }

        return sccs;

    }
};
