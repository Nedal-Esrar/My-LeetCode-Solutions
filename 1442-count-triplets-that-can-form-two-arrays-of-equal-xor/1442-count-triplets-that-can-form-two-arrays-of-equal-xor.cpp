class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        
        int ret = 0;
        
        int prf_xor = 0;
        
        unordered_map<int, int> prf_xor_cnt{{0, 1}};
        
        unordered_map<int, int> prf_xor_idx_sm;
        
        for (int i = 0; i < n; ++i) {
            prf_xor ^= arr[i];
            
            ret += prf_xor_cnt[prf_xor]++ * i - prf_xor_idx_sm[prf_xor];
            
            prf_xor_idx_sm[prf_xor] += i + 1;
        }
        
        return ret;
    }
};