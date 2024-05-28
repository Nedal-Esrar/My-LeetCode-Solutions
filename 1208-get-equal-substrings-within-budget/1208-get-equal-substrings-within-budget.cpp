class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        
        int ret = 0;
        
        int st = 0;
        
        int cur = 0;
        
        for (int en = 0; en < n; ++en) {
            cur += abs(s[en] - t[en]);
            
            while (cur > maxCost) {
                cur -= abs(s[st] - t[st]);
                
                ++st;
            }
            
            ret = max(ret, en - st + 1);
        }
        
        return ret;
    }
};