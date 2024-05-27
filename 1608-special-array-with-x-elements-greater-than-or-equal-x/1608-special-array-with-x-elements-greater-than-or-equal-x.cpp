class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> frq(n + 1);
        
        for (int i = 0; i < n; ++i) {
            ++frq[min(n, nums[i])];
        }
        
        int cnt = 0;
        
        for (int i = n; i > 0; --i) {
            cnt += frq[i];
            
            if (i == cnt) {
                return i;
            }
        }
        
        return -1;
    }
};