/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        TreeNode* root = NULL;
        solve(nums, &root, start, end);
        return root;
    }
    
    void solve(vector<int> nums, TreeNode** root, int start, int end)
    {
        if(start>end)
        {
            return;
        }
        int mid = (end-start)/2+start;
        *root = new TreeNode(nums[mid]);
        solve(nums, &((*root)->left), start, mid-1);
        solve(nums, &((*root)->right), mid+1, end);
    }
};
