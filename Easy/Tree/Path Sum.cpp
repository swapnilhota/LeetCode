/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum, 0);
    }
    
    bool solve(TreeNode* node, int target, int sum)
    {
        if(node==NULL)
        {
            return false;
        }
        sum += node->val;
        if(node->left==NULL && node->right==NULL)
        {
            if(sum==target)
            {
                return true;
            }
        }
        bool a1 = solve(node->left, target, sum);
        bool a2 = solve(node->right, target, sum);
        
        return a1||a2;
    }
};
