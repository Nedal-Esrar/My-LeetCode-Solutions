class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        
        stack<int> stk;
        unordered_map<int, int> idx;

        for (int i = n - 1; i > -1; --i) {
            while (!stk.empty() && stk.top() < nums2[i]) {
                stk.pop();
            }

            if (!stk.empty()) {
                idx[nums2[i]] = stk.top();
            } else {
                idx[nums2[i]] = -1;
            }

            stk.push(nums2[i]);
        }
        
        int m = nums1.size();

        vector<int> ans(m, -1);

        for (int i = 0; i < m; i++) {
            ans[i] = idx[nums1[i]];
        }

        return ans;
    }
};