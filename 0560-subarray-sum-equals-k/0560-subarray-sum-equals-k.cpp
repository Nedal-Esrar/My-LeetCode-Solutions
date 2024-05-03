class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        
        int ret = 0;
        
        unordered_map<int, int> prf_frq;
        prf_frq[0] = 1;
        
        for (int e : nums) {
            sum += e;
            
            if (prf_frq.find(sum - k) != prf_frq.end()) {
                ret += prf_frq[sum - k];
            }
            
            ++prf_frq[sum];
        }
        
        return ret;
    }
};