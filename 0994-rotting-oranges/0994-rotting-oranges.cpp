class Solution {
    const int delta[5]{1, 0, -1, 0, 1};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        /*
            Do a Breadth-First Search traversal starting from the rotten oranges
            and expand them to make fresh ones also rotten
            if the number of affected fresh oranges equals the total number of them
            then the answer is how many levels are expanded in the BFS traversal minus one (the first level is                   actually rotten), else then there is no answer (-1)
        */
        
        int n = grid.size(), m = grid[0].size();
        
        int total_fresh = 0;
        
        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                
                if (grid[i][j] == 1) {
                    ++total_fresh;
                } else {
                    q.push({i, j});
                }
            }
        }
        
        int total_days = 0;
        
        int total_affected = 0;
        
        while (!q.empty()) {
            ++total_days;
            
            int sz = q.size();
            
            for (int i = 0; i < sz; ++i) {
                auto [x, y] = q.front();
                q.pop();
                
                for (int i = 0; i < 4; ++i) {
                    int new_x = x + delta[i];
                    int new_y = y + delta[i + 1];
                    
                    if (are_boundaries_valid(new_x, new_y, n, m) && grid[new_x][new_y] == 1) {
                        ++total_affected;
                        
                        grid[new_x][new_y] = 2;
                        
                        q.push({new_x, new_y});
                    }
                }
            }
        }
        
        return total_affected == total_fresh ? max(0, total_days - 1) : -1;
    }
private:
    bool are_boundaries_valid(int x, int y, int n, int m) {
        return x > -1 && x < n && y > -1 && y < m;
    }
};