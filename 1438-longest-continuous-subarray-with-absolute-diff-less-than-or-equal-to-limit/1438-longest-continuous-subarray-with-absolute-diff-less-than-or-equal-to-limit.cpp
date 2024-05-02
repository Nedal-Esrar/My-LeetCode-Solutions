class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> st;
        
        int ret = 0;
        
        int start = 0;
        
        int n = nums.size();
        
        for (int end = 0; end < n; ++end) {
            st.insert(nums[end]);
            
            while (*st.rbegin() - *st.begin() > limit) {
                st.erase(st.find(nums[start]));
                
                ++start;
            }
            
            ret = max(ret, end - start + 1);
        }
        
        return ret;
    }
};