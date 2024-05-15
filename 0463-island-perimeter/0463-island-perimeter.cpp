class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                
                int c = 0; 
                
                if (i > 0 && grid[i - 1][j] == 1) {
                    ++c;
                } 
                
                if (i < grid.size() - 1 && grid[i + 1][j] == 1) {
                    ++c;
                }
                
                if (j > 0 && grid[i][j - 1] == 1) {
                    ++c;
                }
                
                if (j < grid[0].size() - 1 && grid[i][j + 1] == 1) {
                    ++c;
                }
                
                perimeter += 4 - c;
            }
        }
        
        return perimeter;
    }
};