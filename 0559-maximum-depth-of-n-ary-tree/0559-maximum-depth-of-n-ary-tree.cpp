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
        if (root == nullptr) {
            return 0;
        }
        
        int ret = 1;
        
        for (Node* child : root->children) {
            ret = max(ret, 1 + maxDepth(child));
        }
        
        return ret;
    }
};


// 1 + max{depth(root->children)}