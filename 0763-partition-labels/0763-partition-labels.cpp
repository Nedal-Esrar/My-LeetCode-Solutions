class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        
        int last_idx[26]{};
        
        for (int i = 0; i < n; ++i) {
            last_idx[s[i] - 'a'] = i;
        }
        
        int cur_len = 0;
        
        int last_idx_to_reach = 0;
        
        vector<int> ret;
        
        for (int i = 0; i < n; ++i) {
            last_idx_to_reach = max(last_idx_to_reach, last_idx[s[i] - 'a']);
            
            ++cur_len;
            
            if (last_idx_to_reach == i) {
                ret.push_back(cur_len);
                
                cur_len = 0;
            }
        }
        
        return ret;
    }
};