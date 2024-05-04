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
        
        queue<pair<Node*, int>> q;
        
        q.push({root, 1});
        
        int ret = 1;
        
        while (!q.empty()) {
            auto [front_node, depth] = q.front();
            q.pop();
            
            ret = max(ret, depth);
            
            for (Node* child : front_node->children) {
                q.push({child, depth + 1});
            }
        }
        
        return ret;
    }
};

// Queue
// (1, 1) -> (3, 2), 2, 4 -> 2, 4, 5, 6