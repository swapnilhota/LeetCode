/*
Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

 

Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 100].
0 <= Node.val <= 105
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
    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        helper(root, v);
        sort(v.begin(), v.end());
        int ans=INT_MAX;
        for(int i=1; i<v.size(); i++)
        {
            ans = min(ans, v[i]-v[i-1]);
        }
        return ans;
    }
    void helper(TreeNode* root, vector<int> &v)
    {
        if(!root) return;
        v.push_back(root->val);
        helper(root->left, v);
        helper(root->right, v);
    }
};
