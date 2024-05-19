class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sm = 0;
        
        int cnt = 0;
        
        for (int num : nums) {
            if ((num ^ k) > num) {
                ++cnt;
                
                sm += num ^ k;
            } else {
                sm += num;
            }
        }
        
        if (cnt % 2 == 0) {
            return sm;
        }
        
        int mn = INT_MAX;
        
        for (int num : nums) {
            mn = min(mn, abs(num - (num ^ k)));
        }
        
        return sm - mn;
    }
};