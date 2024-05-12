class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ret = 0;
        
        while (maxDoubles != 0 && target != 1) {
            if (target & 1) {
                --target;
                
                ++ret;
            }
            
            target >>= 1;
            
            ++ret;
            
            --maxDoubles;
        }
        
        return ret + target - 1;
    }
};