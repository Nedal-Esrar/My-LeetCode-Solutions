class Solution {
public:
    int appendCharacters(string s, string t) {
        int s_i = 0, t_i = 0;
        
        while (s_i < s.length() && t_i < t.length()) {
            if (s[s_i] == t[t_i]) {
                ++t_i;
            }
            
            ++s_i;
        }
        
        return t.length() - t_i;
    }
};