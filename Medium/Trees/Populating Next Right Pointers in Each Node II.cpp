/*
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
        {
            return root;
        }
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        pair<Node*, int> prev = {NULL, 0};
        
        while(!q.empty())
        {
            Node* curr_node = q.front().first;
            int curr_lvl = q.front().second;
            q.pop();
            
            if(curr_node->left)
            {
                q.push({curr_node->left, curr_lvl+1});
            }
            if(curr_node->right)
            {
                q.push({curr_node->right, curr_lvl+1});
            }
            
            if((prev.first)==NULL)
            {
                prev = {curr_node, curr_lvl};
            }
            else
            {
                if((prev.second)==curr_lvl)
                {
                    (prev.first)->next = curr_node;
                }
                prev = {curr_node, curr_lvl};
            }
        }
        
        return root;
    }
};
