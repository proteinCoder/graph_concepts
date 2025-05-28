typedef pair<int, int> pii;
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        //adj
        vector<vector<pair<int,int>>> adj(V); // node -> {neigh,weight}
        for(auto &it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        
        vector<int> explored(V,0);
        vector<int> dist(V,INT_MAX);
        
        dist[src]=0;
        
        priority_queue<pii,vector<pii>,greater<pii>> p;
        p.push({0,src});
            
        while(!p.empty()){
            
            int node = p.top().second;
            p.pop();
            if(explored[node]) continue;
            
            //mark the node explored
            explored[node]=1;
            
            //relax edges
            for(auto &it: adj[node]){
                int neigh = it.first;
                int d     = it.second;
                if(!explored[neigh] && dist[neigh]>dist[node]+d){
                    dist[neigh] = dist[node]+d;
                    p.push({dist[neigh],neigh});
                }
            }
        }
        
        return dist;
    }
