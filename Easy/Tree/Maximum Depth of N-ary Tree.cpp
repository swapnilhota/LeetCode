/*
Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        return solve(root, 0);
    }
    
    int solve(Node* node, int ans)
    {
        if(node==NULL)
        {
            return 0;
        }
        int res = ans+1;
        vector<Node*> v = node->children;
        for(auto i: v)
        {
            res = max(res, solve(i, ans+1));
        }
        return res;
    }
};
