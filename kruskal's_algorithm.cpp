class Solution {
  class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);  // Rank = height of tree
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        // Union by rank
        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
  
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        vector<pair<int,pair<int,int>>> edges;
        for(int u=0;u<V;u++){
            for(auto &it:adj[u]){
                int  v = it[0];
                int  wt = it[1];
                edges.push_back({wt,{u,v}});
            }
        }
        
        sort(edges.begin(), edges.end());  // Step 1: Sort edges by weight
        
        DSU ds(V);  // Step 2: Initialize DSU
        int mstWeight = 0;
        int edgesUsed = 0;
    
        for (auto &it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (ds.find(u)!=ds.find(v)) {  // Step 3: Check if it forms a cycle
                
                ds.unite(u,v);
                
                mstWeight += wt;
                
                edgesUsed++;
                
                if (edgesUsed == V - 1) break;  // MST complete
            }
        }
    
        return mstWeight;
            
    }
};
