class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<bool> &vis){
        vis[node]=1;
        for(auto &it:adj[node]){
            if(!vis[it]) dfs(it,adj,vis);
        }
    }
    int isEulerCircuit(int V, vector<int> adj[]) {
        // Code here
        vector<int> deg(V,0);
        int oddDeg=0;
        for(int i=0;i<V;i++){
            deg[i] = adj[i].size();
            if(deg[i]%2)
                oddDeg++;
        }
        if(oddDeg!=0 && oddDeg!=2) return 0;
        
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(deg[i]){
                dfs(i,adj,vis);
                break;
            }
        }
        
        for(int i=0;i<V;i++){
            if(!vis[i] && deg[i]) return 0;
        }
        
        return oddDeg==0?2:1; // 2:eulerian circuit, 1:eulerian path
        
    }
};
