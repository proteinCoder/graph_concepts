class Solution {
public:
    bool dfs(int src, vector<vector<int>>& graph, vector<int>& color, int clr) {
        color[src] = clr;
        for (auto it : graph[src]) {
            if (color[it] == -1) {
                if (dfs(it, graph, color, 1-clr) == false) {
                    return false;
                }
            } else if (color[it] == color[src])
                return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (dfs(i, graph, color, 0) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};
