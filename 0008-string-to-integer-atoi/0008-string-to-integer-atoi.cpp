class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        
        int sign = 1;
        
        long long ans = 0;
        
        while (i < s.length() && s[i] == ' ') {
            ++i;
        }
        
        if (s[i] == '-') {
            sign = -1;
            
            ++i;
        } else if (s[i] == '+') {
            ++i;
        }
        
        while (i < s.length()) {
            if (!isdigit(s[i])) {
                break;
            }
            
            ans = ans * 10 + s[i] - '0';

            if (ans > INT_MAX) {
                return sign == -1 ? INT_MIN : INT_MAX;
            }

            ++i;
        }
        
        return sign * ans;
    }
};