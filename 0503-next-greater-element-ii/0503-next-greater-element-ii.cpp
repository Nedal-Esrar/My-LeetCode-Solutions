class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ret(n);
        
        stack<int> stk;
        
        for (int i = 2 * n - 1; i > -1; --i) {
            while (!stk.empty() && nums[stk.top()] <= nums[i % n]) {
                stk.pop();
            }
            
            ret[i % n] = stk.empty() ? -1 : nums[stk.top()];
            
            stk.push(i % n);
        }
        
        return ret;
    }
};