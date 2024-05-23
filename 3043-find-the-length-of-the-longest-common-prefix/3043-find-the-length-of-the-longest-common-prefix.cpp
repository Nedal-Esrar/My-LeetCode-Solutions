class Solution {
private:
    class TrieNode {
        public:
        TrieNode* children[10];
    };
    
    void add(TrieNode* root, int num) {
        for (char digit : to_string(num)) {
            if (root->children[digit - '0'] == nullptr) {
                root->children[digit - '0'] = new TrieNode();
            }
            
            root = root->children[digit - '0'];
        }
    }
    
    int get_longest_common_prefix(TrieNode* root, int num) {
        int ret = 0;
        
        for (char digit : to_string(num)) {
            if (root->children[digit - '0'] == nullptr) {
                break;
            }
            
            ++ret;
            
            root = root->children[digit - '0'];
        }
        
        return ret;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ret = 0;
        
        TrieNode* root = new TrieNode();
        
        for (int num : arr1) {
            add(root, num);
        }
        
        for (int num : arr2) {
            ret = max(ret, get_longest_common_prefix(root, num));
        }
        
        return ret;
    }
};