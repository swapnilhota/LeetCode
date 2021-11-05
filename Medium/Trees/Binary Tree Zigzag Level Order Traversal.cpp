/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        map<int, vector<int>> mp;
        dfs(root, 0, mp);
        int i=1;
        while(1)
        {
            if(mp[i].size()==0)
            {
                break;
            }
            reverse(mp[i].begin(), mp[i].end());
            i += 2;
        }
        vector<vector<int>> res;
        for(auto x: mp)
        {
            if(x.second.size()==0)
            {
                break;
            }
            res.push_back(x.second);
        }
        return res;
    }
    void dfs(TreeNode* root, int level, map<int, vector<int>> &mp)
    {
        if(root==NULL)
        {
            return;
        }
        mp[level].push_back(root->val);
        dfs(root->left, level+1, mp);
        dfs(root->right, level+1, mp);
    }
};
