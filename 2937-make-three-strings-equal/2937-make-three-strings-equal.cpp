class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length(), l = s3.length();
        
        int i = 0, j = 0, k = 0;
        
        if (s1[i] != s2[j] || s2[j] != s3[k]) {
            return -1;
        }
        
        while (i < n && j < m && k < l) {
            if (s1[i] != s2[j] || s2[j] != s3[k]) {
                break;
            }
            
            ++i;
            ++j;
            ++k;
        }
        
        return n - i + m - j + l - k;
    }
};