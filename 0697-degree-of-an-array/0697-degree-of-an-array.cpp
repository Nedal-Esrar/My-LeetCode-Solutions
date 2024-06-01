class Solution {
    struct NumChunk {
        int frq;
        int left_idx;
        int right_idx;
    };
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, NumChunk> mp;
        
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]].left_idx = i;
            }
            
            ++mp[nums[i]].frq;
            
            mp[nums[i]].right_idx = i;
        }
        
        int mx_frq = 0;
        
        int ret = nums.size();
        
        for (auto& [_, num_chunk] : mp) {
            if (num_chunk.frq > mx_frq) {
                mx_frq = num_chunk.frq;
                
                ret = num_chunk.right_idx - num_chunk.left_idx + 1;
            } else if (num_chunk.frq == mx_frq && num_chunk.right_idx - num_chunk.left_idx + 1 < ret) {
                ret = num_chunk.right_idx - num_chunk.left_idx + 1;
            } 
        }
        
        return ret;
    }
};