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
    int findTilt(TreeNode* root) {
        int total_tilt = 0;
        
        function<int(TreeNode*)> solve = [&](TreeNode* root) -> int {
            if (root == nullptr) {
                return 0;
            }
            
            int left_subtree_sum = solve(root->left);
            int right_subtree_sum = solve(root->right);
            
            total_tilt += abs(left_subtree_sum - right_subtree_sum);
            
            return root->val + left_subtree_sum + right_subtree_sum;
        };
        
        solve(root);
        
        return total_tilt;
    }
};