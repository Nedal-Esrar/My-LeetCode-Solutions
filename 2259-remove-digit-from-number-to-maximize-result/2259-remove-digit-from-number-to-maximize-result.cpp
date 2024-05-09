class Solution {
public:
    string removeDigit(string number, char digit) {
        int idx = -1;
        
        for (int i = 0; i < number.length(); ++i) {
            if (number[i] == digit) {
                idx = i;
                
                if (i < number.length() - 1 && digit < number[i + 1]) {
                    break;
                }
            }
        }
        
        number.erase(number.begin() + idx);
        
        return number;
    }
};