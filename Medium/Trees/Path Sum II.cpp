/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> tmp;
        solve(root, targetSum, 0, tmp, res);
        return res;
    }
    
    void solve(TreeNode* root, int targetSum, int sum, vector<int> tmp, vector<vector<int>> &res)
    {
        if(root==NULL)
        {
            return;
        }
        sum += root->val;
        tmp.push_back(root->val);
        
        if(sum==targetSum)
        {
            if(root->left==NULL and root->right==NULL)
            {
                res.push_back(tmp);
            }
        }
        solve(root->left, targetSum, sum, tmp, res);
        solve(root->right, targetSum, sum, tmp, res);
    }
};
