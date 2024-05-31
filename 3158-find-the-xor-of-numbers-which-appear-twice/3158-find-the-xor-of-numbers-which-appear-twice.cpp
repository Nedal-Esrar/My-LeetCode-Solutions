class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        long long nums_msk = 0;
        
        int ret = 0;
        
        for (int num : nums) {
            if (nums_msk >> num & 1) {
                ret ^= num;
            }
            
            nums_msk |= 1ll << num;
        }
        
        return ret;
    }
};