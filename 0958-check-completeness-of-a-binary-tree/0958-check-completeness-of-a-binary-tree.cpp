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
    bool isCompleteTree(TreeNode* root) {
        int tree_size = count_nodes(root);
        
        return is_complete(root, 1, tree_size);
    }
private:
    int count_nodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        return 1 + count_nodes(root->left) + count_nodes(root->right);
    }
    
    bool is_complete(TreeNode* root, int idx, int max_idx) {
        if (root == nullptr) {
            return true;
        }
        
        if (idx > max_idx) {
            return false;
        }
        
        return is_complete(root->left, idx << 1, max_idx) &&
               is_complete(root->right, idx << 1 | 1, max_idx);
    }
};