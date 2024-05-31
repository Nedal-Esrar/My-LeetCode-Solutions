class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;
        
        for (int num : nums) {
            xr ^= num;
        }
        
        unsigned int bit = xr & -(unsigned int)xr;
        
        int fr_ret = 0;
        
        for (int num : nums) {
            if (num & bit) {
                fr_ret ^= num;
            }
        }
        
        return {fr_ret, fr_ret ^ xr};
    }
};