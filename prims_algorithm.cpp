class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    typedef pair<int,int> pii;
    int spanningTree(int V, vector<vector<int>> adj[]) {
    
        vector<bool> inMST(V, false);   // To track included vertices
        priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap {weight, node}
        pq.push({0, 0}); // Start from node 0 with weight 0
    
        int totalWeight = 0;
    
        while (!pq.empty()) {
            auto it    = pq.top();
            int weight = it.first;
            int  u     = it.second;
            pq.pop();
    
            if (inMST[u]) continue; // Skip if already included
            inMST[u] = true;
            totalWeight += weight;
    
            for (auto &it : adj[u]) {
                int v = it[0];
                int w = it[1];
                if (!inMST[v]) {
                    pq.push({w, v});
                }
            }
        }
    
        return totalWeight;
    }
};
