class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        
        int ret = INT_MAX;
        
        int mismatch0 = 0, mismatch1 = 0;
        
        for (int i = 0; i < 2 * n; ++i) {
            if (s[i % n] != '0' + i % 2) {
                ++mismatch0;
            }
            
            if (s[i % n] != '0' + 1 - i % 2) {
                ++mismatch1;
            }
            
            if (i >= n) {
                if (s[i - n] != '0' + (i - n) % 2) {
                    --mismatch0;
                }

                if (s[i - n] != '0' + 1 - (i - n) % 2) {
                    --mismatch1;
                }
            }
            
            if (i >= n - 1) {
                ret = min({ret, mismatch0, mismatch1});
            }
        }
        
        return ret;
    }
};