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
    int distributeCoins(TreeNode* root) {
        int ret = 0;
        
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }  
            
            int left = dfs(root->left);
            int right = dfs(root->right);
            
            ret += abs(left) + abs(right);
            
            return root->val + left + right - 1;
        };
        
        dfs(root);
        
        return ret;
    }
};