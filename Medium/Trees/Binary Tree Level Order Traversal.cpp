/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }
        
        int h=0;
        unordered_map<int, vector<int>> mp;
        helper(root, mp, h, 0);
        
        for(int i=0; i<=h; i++)
        {
            ans.push_back(mp[i]);
        }
        return ans;
    }
    
    void helper(TreeNode* node, unordered_map<int, vector<int>> &mp, int &h, int lvl)
    {
        if(node==NULL)
        {
            return;
        }
        h=max(h, lvl);
        mp[lvl].push_back(node->val);
        helper(node->left, mp, h, lvl+1);
        helper(node->right, mp, h, lvl+1);
    }
};
