class Solution {
public:
    bool checkRecord(string s) {
        int count_absent = 0;
        int count_late = 0;
        
        for (char c : s) {
            if (c == 'P') {
                count_late = 0;
            } else if (c == 'L') {
                if (++count_late == 3) {
                    return false;
                }
            } else {
                if (++count_absent == 2) {
                    return false;
                }
                
                count_late = 0;
            }
        }
        
        return true;
    }
};