/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<int, vector<int>> adj;
        helper(root, root->val, adj);
        
        //bfs
        queue<pair<int, int>> q;
        q.push(make_pair(target->val, 0));
        map<int, int> vis;
        vector<int> ans;
        
        while(!q.empty())
        {
            int curr = q.front().first;
            int d = q.front().second;
            q.pop();
            vis[curr]++;
            
            if(d==k)
            {
                ans.push_back(curr);
            }
            else if(d<k)
            {
                for(auto next: adj[curr])
                {
                    if(vis[next]==0)
                    {
                        q.push(make_pair(next, d+1));
                    }
                }
            }
        }
        
        return ans;
    }
    
    void helper(TreeNode* root, int prev, map<int, vector<int>> &adj)
    {
        if(root==NULL) return;
        
        if(prev!=root->val)
        {
            adj[prev].push_back(root->val);
            adj[root->val].push_back(prev);
        }
        
        helper(root->left, root->val, adj);
        helper(root->right, root->val, adj);
    }
};
