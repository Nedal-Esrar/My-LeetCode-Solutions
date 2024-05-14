class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int m = grid[0].size();
        
        int ret = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ret = max(ret, dfs(grid, n, m, i, j));
            }
        }
        
        return ret;
    }

private:
    const vector<int> DELTA = {0, 1, 0, -1, 0};

    int dfs(vector<vector<int>>& grid, int rows,
            int cols, int row, int col) {
        if (row < 0 || col < 0 || row == rows || col == cols ||
            grid[row][col] == 0) {
            return 0;
        }
        
        int mx = 0;

        int original_value = grid[row][col];
        
        grid[row][col] = 0;

        for (int i = 0; i < 4; ++i) {
            mx = max(mx, dfs(grid, rows, cols,
                                      DELTA[i] + row,
                                      DELTA[i + 1] + col));
        }

        grid[row][col] = original_value;
        
        return mx + original_value;
    }
};