class Solution {
  public:
    // Function to detect cycle using DSU in an undirected graph.
    class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union by rank
    void unionSet(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }

    }
};
    int detectCycle(int V, vector<int> adj[]) {
        // Code here
        DSU ds(V);
        for(int u=0;u<V;u++){
            for(auto v:adj[u]){
                if(u<v){
                    int pu = ds.find(u);
                    int pv = ds.find(v);
                    if(pu == pv) return true;
                    ds.unionSet(pu,pv);
                }
            }
        }
        return false;
        
    }
};
