class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int ret = 0;
        
        int n = nums.size();
        
        int init_sum = nums[0] + nums[1];
        
        for (int i = 0; i < n - 1; i += 2) {
            if (nums[i] + nums[i + 1] != init_sum) {
                break;
            }
            
            ++ret;
        }
        
        return ret;
    }
};