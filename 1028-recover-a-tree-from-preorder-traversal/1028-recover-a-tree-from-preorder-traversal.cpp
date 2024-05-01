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
    TreeNode* recoverFromPreorder(string s) {
        int n = s.length();
        
        int level = 0;
        
        stack<TreeNode*> stk;
        
        for (int i = 0; i < n;) {
            int num = 0;
            
            while (i < n && isdigit(s[i])) {
                num *= 10;
                num += s[i] - '0';
                ++i;
            }
            
            while (stk.size() > level) {
                stk.pop();
            }
            
            TreeNode* node = new TreeNode(num);
            
            if (!stk.empty()) {
                if (stk.top()->left == nullptr) {
                    stk.top()->left = node;
                } else {
                    stk.top()->right = node;
                }
            }
            
            level = 0;

            while (i < n && s[i] == '-') {
                ++level;
                ++i;
            }
            
            stk.push(node);
        }
        
        while (stk.size() > 1) {
            stk.pop();
        }
        
        return stk.top();
    }
};