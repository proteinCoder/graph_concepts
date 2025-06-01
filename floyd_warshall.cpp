    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
    
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (dist[i][k] == 1e8) continue; // Skip if i->k is unreachable
                for (int j = 0; j < n; ++j) {
                    if (dist[k][j] == 1e8) continue; // Skip if k->j is unreachable
    
                    int throughK = dist[i][k] + dist[k][j];
    
                    // If no direct path i->j OR a shorter path through k is found
                    if (throughK < dist[i][j]) {
                        dist[i][j] = throughK;
                    }
                }
            }
        }
    }
