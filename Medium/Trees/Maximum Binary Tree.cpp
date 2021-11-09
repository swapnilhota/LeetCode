/*
You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:

Create a root node whose value is the maximum value in nums.
Recursively build the left subtree on the subarray prefix to the left of the maximum value.
Recursively build the right subtree on the subarray suffix to the right of the maximum value.
Return the maximum binary tree built from nums.
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* res=NULL;
        solve(res, nums, nums.begin(), nums.end());
        return res;
    }
    
    void solve(TreeNode* &res, vector<int> nums, vector<int>::iterator itr_begin, vector<int>::iterator itr_end)
    {
        if(itr_begin==itr_end)
        {
            return;
        }
        
        auto itr_max = max_element(itr_begin, itr_end);
        
        res = new TreeNode(*itr_max);
        
        solve(res->left, nums, itr_begin, itr_max);
        solve(res->right, nums, ++itr_max, itr_end);
    }
};
