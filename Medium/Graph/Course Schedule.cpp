/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 105
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses+1);
        for(auto e: prerequisites)
        {
            adj[e[1]].push_back(e[0]);
        }
        // detect loop
        vector<int> rec_stack(numCourses+1, 0);
        vector<int> vis(numCourses+1, 0);
        
        for(int i=0; i<numCourses; i++)
        {
            if(!vis[i])
            {
                if(dfs(adj, i, vis, rec_stack))
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool dfs(vector<vector<int>> &adj, int curr, vector<int> &vis, vector<int> &rec_stack)
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
                if(dfs(adj, next, vis, rec_stack))
                {
                    return true;
                }
            }
        }
        
        rec_stack[curr] = false;
        
        return false;
    }
};
