class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int frq[1024];
        
        long long ret = 0;
        
        int prfMsk = 0;
        
        frq[0] = 1;
        
        for (char c : word) {
            prfMsk ^= 1 << (c - 'a');
            
            ret += frq[prfMsk];
            
            for (int i = 0; i < 10; ++i) {
                ret += frq[prfMsk ^ (1 << i)];
            }
            
            ++frq[prfMsk];
        }
        
        return ret;
    }
};