class Solution {
    const int delta[5]{1, 0, -1, 0, 1};
public:
    int swimInWater(vector<vector<int>>& grid) {
        /*
            navigate greedily through the path the has the minimum cost (max)
            using dijkstra's algorithm until the point (n - 1, n - 1) is reached.
        */
        
        int n = grid.size();
        
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX)); 
        
        priority_queue<
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>> q;
        
        dist[0][0] = grid[0][0];
        q.push({grid[0][0], {0, 0}});
        
        while (!q.empty()) {
            auto [dis, coor] = q.top();
            auto [x, y] = coor;
            q.pop();
            
            if (dis > dist[x][y]) {
                continue;
            }
            
            if (x == n - 1 && y == n - 1) {
                return dis;
            }
            
            for (int i = 0; i < 4; ++i) {
                int new_x = x + delta[i];
                int new_y = y + delta[i + 1];
                
                if (are_boundaries_valid(new_x, new_y, n, n) && dist[new_x][new_y] > max(grid[new_x][new_y], dis)) {
                    dist[new_x][new_y] = max(grid[new_x][new_y], dis);
                    q.push({dist[new_x][new_y], {new_x, new_y}});
                }
            }
        }
        
        return dist[n - 1][n - 1];
    }
    
private:
    bool are_boundaries_valid(int x, int y, int n, int m) {
        return x > -1 && x < n && y > -1 && y < m;
    }
};