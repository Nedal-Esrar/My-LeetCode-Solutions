class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool vis[26]{};
    
        for (char c : allowed) {
            vis[c - 'a'] = true;
        }
        
        int ret = words.size();
        
        for (string word: words) {
            for (char c: word) {
                if (!vis[c - 'a']) {
                    --ret;
                    
                    break;
                }
            }
        }
    
        return ret;
    }
};