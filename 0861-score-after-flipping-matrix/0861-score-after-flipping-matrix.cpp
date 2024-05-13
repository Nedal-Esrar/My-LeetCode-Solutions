class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        int ret = (1 << (m - 1)) * n;
        
        for (int i = 1; i < m; ++i) {
            int cnt = 0;
            
            for (int j = 0; j < n; ++j) {
                if (grid[j][i] == grid[j][0]) { 
                    ++cnt;
                }
            }
            
            ret += max(cnt, n - cnt) * (1 << (m - 1 - i));
        }
        
        return ret;
    }
};