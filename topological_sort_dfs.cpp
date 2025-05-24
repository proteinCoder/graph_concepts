class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adj,
             stack<int>& st) {
        
      visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, visited, adj, st);
            }
        }
        st.push(node);
    }
    
    vector<int> topologicalSort(vector<vector<int>> adj) {
        int n = adj.size();
        vector<int> visited(n, 0);
        stack<int> st;
        
        //calling dfs for all not visited nodes
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                dfs(i, visited, adj, st);
        }
        
        //getting toposort in the ans verctor
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
