/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
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
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        solve(root, 0, ans);
        return ans;
    }
    
    int solve(TreeNode* node, int h, bool &ans)
    {
        if(node==NULL)
        {
            return h;
        }
        int h1 = solve(node->left, h+1, ans);
        int h2 = solve(node->right, h+1, ans);
        if(abs(h1-h2)>1)
        {
            ans=false;
        }
        return max(h1, h2);
    }
};
