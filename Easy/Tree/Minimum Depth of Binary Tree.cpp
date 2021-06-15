/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.
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
    int minDepth(TreeNode* root) {
        return solve(root, 0);
    }
    
    int solve(TreeNode* node, int ans)
    {
        if(node==NULL)
        {
            return ans;
        }
        if(node->left==NULL && node->right==NULL)
        {
            return ans+1;
        }
        else if(node->left==NULL)
        {
            return solve(node->right, ans+1);
        }
        else if(node->right==NULL)
        {
            return solve(node->left, ans+1);
        }
        else
        {
            return min(solve(node->left, ans+1), solve(node->right, ans+1));
        }
    }
};
