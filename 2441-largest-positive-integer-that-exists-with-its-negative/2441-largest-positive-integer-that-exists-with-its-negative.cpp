class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int i = 0, j = nums.size() - 1;
        
        while (i < j && nums[i] < 0 && nums[j] > 0) {
            if (nums[i] + nums[j] == 0) {
                return nums[j];
            } else if (nums[i] + nums[j] < 0) {
                ++i;
            } else {
                --j;
            }
        }
        
        return -1;
    }
};