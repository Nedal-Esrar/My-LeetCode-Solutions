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
    bool evaluateTree(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == 1 ? true : false;
        }
        
        bool ret;
        
        if (root->val == 2) {
            ret = false;
            
            if (root->left != nullptr) {
                ret = ret || evaluateTree(root->left);
            }
            
            if (root->right != nullptr) {
                ret = ret || evaluateTree(root->right);
            }
        }
        else {
            ret = true;
            
            if (root->left != nullptr) {
                ret = ret && evaluateTree(root->left);
            }
            
            if (root->right != nullptr) {
                ret = ret && evaluateTree(root->right);
            }
        }
        
        return ret;
    }
};