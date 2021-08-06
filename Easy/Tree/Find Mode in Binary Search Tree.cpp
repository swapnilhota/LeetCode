/*
Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [1,null,2,2]
Output: [2]
Example 2:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105
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
    vector<int> findMode(TreeNode* root) {
        
        vector<int> res;
        if(!root)
        {
            return res;
        }
        
        unordered_map<int, int> mp;
        helper(root, mp);
        
        int max_cnt=0;
        
        for(auto i: mp)
        {
            max_cnt=max(max_cnt, i.second);
        }
        
        if(max_cnt==0)
        {
            return res;
        }
        
        for(auto i: mp)
        {
            if(i.second==max_cnt)
            {
                res.push_back(i.first);
            }
        }
        
        return res;
    }
    
    void helper(TreeNode* root, unordered_map<int, int> &mp)
    {
        if(root==NULL)
        {
            return;
        }
        mp[root->val]++;
        helper(root->left, mp);
        helper(root->right, mp);
    }
};
