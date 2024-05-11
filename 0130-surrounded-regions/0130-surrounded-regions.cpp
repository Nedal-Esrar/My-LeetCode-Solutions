class Solution {
    const int delta[5]{1, 0, -1, 0, 1};
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        
        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O') {
                dfs(i, 0, board, n, m);
            }
            
            if (board[i][m - 1] == 'O') {
                dfs(i, m - 1, board, n, m);
            }
        }
        
        for (int i = 0; i < m; ++i) {
            if (board[0][i] == 'O') {
                dfs(0, i, board, n, m);
            }
            
            if (board[n - 1][i] == 'O') {
                dfs(n - 1, i, board, n, m);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
private:
    void dfs(int x, int y, vector<vector<char>>& board, int n, int m) {
        if (!are_boundaries_valid(x, y, n, m) || board[x][y] != 'O') {
            return;
        }
        
        board[x][y] = '#';
        
        for (int i = 0; i < 4; ++i) {
            dfs(x + delta[i], y + delta[i + 1], board, n, m);
        }
    }
    
    bool are_boundaries_valid(int x, int y, int n, int m) {
        return x > -1 && x < n && y > -1 && y < m;
    }
};