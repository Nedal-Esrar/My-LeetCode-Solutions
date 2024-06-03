class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ret = 0;
         
        for (int i = 0; i < 32; i++) {
            int c = 0;
    
            for (int num : nums) {
                c += num >> i & 1;
            }
            
            if (c >= k) {
                ret |= 1 << i;
            }
        }
        
        return ret;
    }
};