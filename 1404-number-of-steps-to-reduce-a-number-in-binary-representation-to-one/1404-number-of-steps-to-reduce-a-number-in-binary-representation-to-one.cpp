class Solution {
public:
    int numSteps(string s) {
        int divs = s.size() - 1, additions = 0, carry = 0;
        
        for (int i = s.size() - 1; i > 0; --i) {
            additions += s[i] - '0' + carry == 1;
            
            carry |= s[i] == '1';
        }
        
        return divs + additions + carry;
    }
};