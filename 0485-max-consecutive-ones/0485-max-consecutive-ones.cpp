class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c1 = 0;
        
        int ret = 0;
        
        for (int num : nums) {
            if (num == 1) {
                ++c1;
            } else {
                ret = max(ret, c1);
                
                c1 = 0;
            }
        }
        
        return max(ret, c1);
    }
};