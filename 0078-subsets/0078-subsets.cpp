class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> ret;
        
        for (int i = 0; i < (1 << n); ++i) {
            vector<int> subset;
            
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    subset.push_back(nums[j]);
                }
            }
            
            ret.push_back(subset);
        }
        
        return ret;
    }
};