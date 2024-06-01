class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        bool one_rot = true, two_rot = true, 
             three_rot = true, four_rot = true;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] != target[j][n - i - 1]) {
                    one_rot = false;
                }
                
                if (mat[i][j] != target[n - i - 1][n - j - 1]) {
                    two_rot = false;
                }
                
                if (mat[i][j] != target[n - j - 1][i]) {
                    three_rot = false;
                }
                
                if (mat[i][j] != target[i][j]) {
                    four_rot = false;
                }
            }
        }
        
        return one_rot || two_rot || three_rot || four_rot;
    }
};