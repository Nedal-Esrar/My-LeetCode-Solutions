class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int ret = 1;
        
        unordered_map<int, map<int, int>> mod_group_frq;
        
        for (int num : nums) {
            ++mod_group_frq[num % k][num];
        }
        
        for (const auto& [_, mod_group] : mod_group_frq) {
            int prv_num = -k, prv1 = 1, prv2, cur;
            
            for (const auto& [num, frq] : mod_group) {
                int skip = prv1;
                
                int take = ((1 << frq) - 1) * (num - prv_num == k ? prv2 : prv1);
                
                cur = skip + take;
                prv2 = prv1;
                prv1 = cur;
                prv_num = num;
            }
            
            ret *= cur;
        }
        
        return ret - 1;
    }
};