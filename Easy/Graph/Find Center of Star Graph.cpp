/*
There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.
*/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> adj;
        for(auto edge: edges)
        {
            adj[edge[0]]++;
            adj[edge[1]]++;
        }
        
        int out_deg=0;
        int center;
        for(auto i: adj)
        {
            if(i.second>out_deg)
            {
                out_deg = i.second;
                center = i.first;
            }
        }
        return center;
    }
};
