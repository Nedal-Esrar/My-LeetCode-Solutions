class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int ret = 1;
        
        int inc = 1, dec = 1;
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                inc = dec + 1;
                dec = 1;
            } else if (nums[i] == nums[i - 1] - 1) {
                dec = inc > 1 ? inc + 1 : 1;
                inc = 1;
            } else {
                inc = dec = 1;
            }
            
            ret = max({ret, inc, dec});
        }
        
        return ret == 1 ? -1 : ret;
    }
};