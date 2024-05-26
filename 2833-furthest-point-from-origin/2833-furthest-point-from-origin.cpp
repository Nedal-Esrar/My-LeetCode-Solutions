class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count_L = 0, count_R = 0, count_any = 0;
        
        for (char move : moves) {
            switch (move) {
                case 'L':
                    ++count_L;
                    break;
                
                case 'R':
                    ++count_R;
                    break;
                    
                case '_':
                    ++count_any;
                    break;
            }
        }
        
        return abs(count_R - count_L) + count_any;
    }
};