class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int i = 0;
        
        int ret = 0;
        
        int n = nums.size();
        
        while (i + 1 < n) {
            if (nums[i] == nums[i + 1]) {
                ++ret;
                
                ++i;
            } else {
                i += 2;
            }
        }
        
        if (i == n - 1) {
            ++ret;
        }
        
        return ret;
    }
};