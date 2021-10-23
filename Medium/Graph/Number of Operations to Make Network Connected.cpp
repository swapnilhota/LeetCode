/*
There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1. 
*/

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges=connections.size();
        if(edges<n-1)
        {
            return -1;
        }
        
        vector<vector<int>> adj(n+1);
        
        for(auto edge: connections)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> vis(n+1, false);
        int connected_comps=0;
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                connected_comps++;
                dfs(adj, i, vis);
            }
        }
        
        return connected_comps-1;
    }
    
    void dfs(vector<vector<int>> &adj, int curr, vector<bool> &vis)
    {
        vis[curr]=true;
        for(auto next: adj[curr])
        {
            if(!vis[next])
            {
                dfs(adj, next, vis);
            }
        }
    }
};
