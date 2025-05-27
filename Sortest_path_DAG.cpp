void toposort(int node, vector<vector<pair<int,int>>> &adj, stack<int> &st,
    vector<int> &vis){
        vis[node]=1;
        for(auto &it:adj[node]){
            if(!vis[it.first]){
                toposort(it.first,adj,st,vis);
            }
        }
        st.push(node);
        
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<E;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        stack<int>st;
        vector<int> vis(V,0);
        toposort(0,adj,st,vis);
        
        vector<int> dist(V,INT_MAX);
        dist[0]=0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto &neigh:adj[node]){
                if(dist[neigh.first] > dist[node]+neigh.second){
                    dist[neigh.first] = dist[node]+neigh.second;
                }
            }
        }
        for(auto &it:dist){
            if(it == INT_MAX) it = -1;
        }
        return dist;
    }
