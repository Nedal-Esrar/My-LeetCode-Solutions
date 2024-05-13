class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        
        int i = 0, cnt= 0 ;
        
        int ret= 0 ;
        
        for (int j = 0; j < n; ++j) {
            if (nums[j] == 0) {
                ++cnt;
            }
            
            while (cnt > k) {
                if (nums[i] == 0) {
                    --cnt;
                }
                
                ++i;
            }
            
            ret = max(ret, j - i + 1);
        }
        
        return ret;
    }
};