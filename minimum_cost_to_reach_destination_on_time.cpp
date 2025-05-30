class Solution {
public:
    typedef pair<int, int> pii; // (neighbor, travel time)

    int minCost(int maxTime, vector<vector<int>>& edges,
                vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pii>> adj(n); // adjacency list: (neighbor, time)

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], t = edge[2];
            adj[u].emplace_back(v, t);
            adj[v].emplace_back(u, t);
        }

        vector<int> minTime(n, INT_MAX);

        // Min-heap: each entry is {cost, time, node}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({passingFees[0], 0, 0}); // cost, time, node
        minTime[0] = 0;

        while (!pq.empty()) {
            vector<int> top = pq.top();
            pq.pop();

            int cost = top[0];
            int time = top[1];
            int node = top[2];

            if (node == n - 1)
                return cost;

            for (auto& [next, t] : adj[node]) {
                int newTime = time + t;
                int newCost = cost + passingFees[next];
                if (newTime <= maxTime && newTime < minTime[next]) {
                    minTime[next] = newTime;
                    pq.push({newCost, newTime, next});
                }
            }
        }

        return -1;
    }
};
