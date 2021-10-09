/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        {
            return node;
        }
        vector<Node*> visited(1000, NULL);
        Node* new_node = new Node(node->val);
        helper(new_node, node, visited);
        return new_node;
    }
    
    void helper(Node* curr, Node* og, vector<Node*> &visited)
    {
        visited[curr->val] = curr;
        for(auto next: og->neighbors)
        {
            if(visited[next->val]==NULL)
            {
                auto new_child = new Node(next->val);
                curr->neighbors.push_back(new_child);
                helper(new_child, next, visited);
            }
            else
            {
                curr->neighbors.push_back(visited[next->val]);
            }
        }
    }
};
