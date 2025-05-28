 vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        //creating adj
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
        
        int cnt=V;
        while(cnt--){
            int node=-1;
            
            //get node having shortest distance from src
            for(int i=0;i<V;i++){
                if(!explored[i] && ((node==-1) || dist[i]<dist[node])){
                    node = i;
                }
            }

            
            //mark the node explored
            explored[node]=1;
            
            //relax edges
            for(auto &it: adj[node]){
                int neigh = it.first;
                int d     = it.second;
                if(!explored[neigh] && dist[neigh]>dist[node]+d){
                    dist[neigh] = dist[node]+d;
                }
            }
        }
        
        return dist;
    }
