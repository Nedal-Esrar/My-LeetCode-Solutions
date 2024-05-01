class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> msk_idx(32, -2);
        msk_idx[0] = -1;
        
        int cur_msk = 0, n = s.length(), ret = 0;
        
        string vowels = "aeiou";
        
        for (int i = 0; i < n; ++i) {
            cur_msk ^= 1 << vowels.find(s[i]) + 1 >> 1;
            
            if (msk_idx[cur_msk] == -2) {
                msk_idx[cur_msk] = i;
            }
            
            ret = max(ret, i - msk_idx[cur_msk]);
        }
        
        return ret;
    }
};