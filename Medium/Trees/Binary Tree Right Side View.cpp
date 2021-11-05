/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> temp;
        map<int, vector<int>> mp;
        if(!root)
        {
            return temp;
        }
        helper(root, mp, 0);
        int i=0;
        while(1)
        {
            if(mp[i].size()==0)
            {
                break;
            }
            int n = mp[i].size();
            temp.push_back(mp[i][n-1]);
            i++;
        }
        return temp;
    }
    
    void helper(TreeNode* root, map<int, vector<int>> &mp, int lvl)
    {
        if(root==NULL)
        {
            return;
        }
        
        mp[lvl].push_back(root->val);
        helper(root->left, mp, lvl+1);
        helper(root->right, mp, lvl+1);
    }
};
