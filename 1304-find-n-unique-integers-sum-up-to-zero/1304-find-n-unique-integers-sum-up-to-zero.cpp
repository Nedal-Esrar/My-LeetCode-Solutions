class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ret;
        
        for (int i = 1; i <= n / 2; ++i) {
            ret.push_back(i);
            ret.push_back(-i);
        }
        
        if (n % 2 == 1) {
            ret.push_back(0);
        }
        
        return ret;
    }
};