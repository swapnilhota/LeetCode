/*
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.
*/

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //articulation points
        
        vector<vector<int>> adj(n+1);
        for(auto edge: connections)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> tin(n+1, -1);
        vector<int> low(n+1, -1);
        vector<int> vis(n+1, 0);
        vector<vector<int>> res;
        int timer=0;
        
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                dfs(adj, i, -1, timer, tin, low, vis, res);
            }
        }
        
        return res;       
    }
    
    void dfs(vector<vector<int>> &adj, int node, int parent, int timer, vector<int> &tin, vector<int> &low, vector<int> &vis, vector<vector<int>> &res)
    {
        vis[node]=1;
        low[node] = tin[node] = timer++;
        for(auto it: adj[node])
        {
            if(it==parent) continue;
            if(!vis[it])
            {
                dfs(adj, it, node, timer, tin, low, vis, res);
                low[node] = min(low[node], low[it]);
                if(low[it]>tin[node])
                {
                    res.push_back({node, it});
                }
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
    }
};
