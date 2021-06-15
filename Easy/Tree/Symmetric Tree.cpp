/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
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
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL)
        {
            return true;
        }
        
        return solve(root->left, root->right);
    }
    
    bool solve(TreeNode* node1, TreeNode* node2)
    {
        if(node1==NULL && node2==NULL)
        {
            return true;
        }
        else if(node1==NULL)
        {
            return false;
        }
        else if(node2==NULL)
        {
            return false;
        }
        else if(node1->val!=node2->val)
        {
            return false;
        }
        else
        {
            return solve(node1->right, node2->left)&&solve(node1->left, node2->right);
        }
    }
};
