class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int frq[10]{};
        
        int ret = 0;
        
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            for (int d = 1; d < 10 ; ++d) {
                if (__gcd(d, nums[i] % 10) == 1) {
                    ret += frq[d];
                }
            }
            
            while (nums[i] > 9) {
                nums[i] /= 10;
            }
            
            ++frq[nums[i]];
        }
        
        return ret;
    }
};