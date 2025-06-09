class Solution {
  public:
    
    bool dfs(int node, int &cnt, vector<vector<int>> &adj, vector<bool>&vis,int &n){
        vis[node] = true;
        cnt++;
        
        if(cnt==n) return true;
        
        for(auto &neigh : adj[node]){
            if(!vis[neigh] && dfs(neigh,cnt,adj,vis,n))
                return true;
        }
        
        vis[node]=false;
        cnt--;
        return false;
        
    }
    
    bool check(int n, int m, vector<vector<int>> edges) {
        // code here
        vector<vector<int>> adj(n);
        for(auto &it:edges){
            int u=it[0]-1, v=it[1]-1;
            adj[u].push_back(v); adj[v].push_back(u);
        }
        
        vector<bool>vis(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(dfs(i,cnt,adj,vis,n))
                return true;
        }
        return false;
    }
};
