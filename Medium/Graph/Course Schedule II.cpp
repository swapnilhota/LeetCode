/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses+1);
        for(auto e: prerequisites)
        {
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> vis(numCourses+1, 0);
        vector<int> rec_stack(numCourses+1, 0); 
        vector<int> order;
        
        for(int i=0; i<numCourses; i++)
        {
            if(!vis[i])
            {
                if(dfs(adj, i, vis, rec_stack, order))
                {
                    vector<int> tmp;
                    return tmp;
                }
            }
        }
        
        reverse(order.begin(), order.end());
        
        return order;
    }
    
    bool dfs(vector<vector<int>> &adj, int curr, vector<int> &vis, vector<int> &rec_stack, vector<int> &order)
    {
        vis[curr] = true;
        rec_stack[curr] = true;
        
        for(auto next: adj[curr])
        {
            if(rec_stack[next])
            {
                return true;
            }
            if(!vis[next])
            {
                if(dfs(adj, next, vis, rec_stack, order))
                {
                    return true;
                }
            }
        }
        
        rec_stack[curr] = false;
        
        order.push_back(curr);
        
        return false;
    }
};
