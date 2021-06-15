/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
        {
            return ans;
        }
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while(!stk.empty() || curr!=NULL)
        {
            while(curr!=NULL)
            {
                stk.push(curr);
                curr=curr->left;
            }
            curr = stk.top();
            stk.pop();
            ans.push_back(curr->val);
            curr=curr->right;
        }
        return ans;
    }
};
