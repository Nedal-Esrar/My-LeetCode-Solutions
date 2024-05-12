class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> result_triplet(3);
        
        for (const auto& triplet : triplets) {
            if (target[0] < triplet[0] || target[1] < triplet[1] || target[2] < triplet[2]) {
                continue;
            }
            
            for (int i = 0; i < 3; ++i) {
                result_triplet[i] = max(result_triplet[i], triplet[i]);
            }
        }
        
        return result_triplet == target;
    }
};