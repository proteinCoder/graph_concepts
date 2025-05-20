## Number of provinces / number of connected components in undirecated graph
# problem link = https://leetcode.com/problems/number-of-provinces/description/

class Solution {
public:
    void dfs(int node,vector<int> &visited,vector<vector<int>> &adj ){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,visited,adj);
            }
        }
    }
    void bfs(int node,vector<int> &visited,vector<vector<int>> &adj){
        queue<int>q;
        q.push(node);
        visited[node]=1;
        while(!q.empty()){
            int n = q.front();
            q.pop();
            for(auto it:adj[n]){
                if(!visited[it]){
                    visited[it]=1;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        //creting adjecency list
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> visited(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                bfs(i,visited,adj);
            }
        }
        return cnt;
    }
};
