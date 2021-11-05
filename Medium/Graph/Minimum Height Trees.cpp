/*
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n==1)
        {
            vector<int> tmp = {0};
            return tmp;
        }
        
        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);
        for(auto e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }
        
        queue<int> q;
        
        for(int i=0; i<n; i++)
        {
            if(deg[i]==1)
            {
                q.push(i);
            }                
        }
        
        while(n>2)
        {
            int cnt = q.size();
            n -= cnt;
            while(cnt--)
            {
                int curr = q.front();
                q.pop();
                
                for(auto next: adj[curr])
                {
                    deg[next]--;
                    if(deg[next]==1)
                    {
                        q.push(next);
                    }
                }
            }
        }
        
        vector<int> ans;
        
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};
