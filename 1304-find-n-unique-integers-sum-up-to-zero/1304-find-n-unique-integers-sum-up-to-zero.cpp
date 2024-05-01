class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ret;
        
        if (n % 2 == 1) {
            ret.push_back(0);
            
            --n;
        }
        
        for (int i = 1; i <= n / 2; ++i) {
            ret.push_back(i);
            ret.push_back(-i);
        }
        
        return ret;
    }
};