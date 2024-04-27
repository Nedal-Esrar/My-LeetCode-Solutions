class Solution {
public:
    bool isNumber(string s) {
        if (s.length() == 0) {
            return false;
        }
        
        int i = s[0] == '+' || s[0] == '-';

        bool hasDecimal = false;
        
        bool hasDigit = false;
        
        for (; i < s.length(); ++i) {            
            if (s[i] >= '0' && s[i] <= '9') {
                hasDigit = true;
                
                continue;
            }
            
            if (s[i] == '.') {
                if (hasDecimal) {
                    return false;
                }
                
                hasDecimal = true;
                
                continue;
            }
            
            if (s[i] == 'e' || s[i] == 'E') {
                if (!hasDigit || i + 1 == s.length()) {
                    return false;
                }
                
                break;
            }
            
            return false;
        }
        
        if (i == s.length()) {
            return hasDigit;
        }

        ++i;

        if (s[i] == '+' || s[i] == '-') {
            if (i + 1 == s.length()) {
                return false;
            }
            
            ++i;
        }
        
        for (; i < s.length(); ++i) {
            if (s[i] < '0' || s[i] > '9') {
                return false;
            }
        }
        
        return true;
    }
};