class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) {
            return {};
        }
        
        vector<vector<int>> ret(m, vector<int>(n));
        
        int idx = 0;
        
        for (int num : original) {
            ret[idx / n][idx % n] = num;
            
            ++idx;
        }
        
        return ret;
    }
};