    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n = adj.size();
        vector<int> dist(n,-1);
        
        dist[src]=0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto &it:adj[node]){
                if(dist[it]==-1){
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
                
            }
        }
        
        return dist;
    }
