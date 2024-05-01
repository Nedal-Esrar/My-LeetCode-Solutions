class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        
        auto check = [&](int md) {
            int cnt = 0;
            
            for (int i = 0; i < n; ++i) {
                cnt += upper_bound(mat[i].begin(), mat[i].end(), md) - mat[i].begin();
            }
            
            return cnt >= k;
        };
        
        int l = -1e9, r = 1e9;
        
        while (l <= r) {
            int md = l + (r - l) / 2;
            
            if (check(md)) {
                r = md - 1;
            } else {
                l = md + 1;
            }
        }
        
        return l;
    }
};