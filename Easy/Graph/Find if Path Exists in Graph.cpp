/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex start to vertex end.

Given edges and the integers n, start, and end, return true if there is a valid path from start to end, or false otherwise.
*/

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int, vector<int>> adj;
        for(auto edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n+1, false);
        visited[start]=true;
        
        for(auto next: adj[start])
        {
            if(visited[next]) continue;
            dfs(adj, next, end, visited);
        }
        return visited[end];
    }
    void dfs(unordered_map<int, vector<int>> &adj, int curr, int end, vector<bool> &visited)
    {
        if(curr==end)
        {
            visited[curr]=true;
            return;
        }
        visited[curr]=true;
        for(auto next: adj[curr])
        {
            if(!visited[next])
            {
                dfs(adj, next, end, visited);
            }
        }
        
        return;
    }
};
