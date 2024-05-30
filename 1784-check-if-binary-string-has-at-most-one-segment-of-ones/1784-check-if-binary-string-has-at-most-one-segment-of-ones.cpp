class Solution {
public:
    bool checkOnesSegment(string s) {
        bool zero_encountered = false;
        
        for (char c : s) {
            if (c == '0') {
                zero_encountered = true;
            } else if (zero_encountered) {
                return false;
            }
        }
        
        return true;
    }
};