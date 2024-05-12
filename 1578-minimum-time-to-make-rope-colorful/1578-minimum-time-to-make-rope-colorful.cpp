class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ret = 0;
        
        char ch = colors[0];
        
        int mx = 0, sm = 0;
        
        int n = colors.length();
        
        for (int i = 0; i < n; ++i) {
            if (colors[i] == ch) {
                sm += neededTime[i];
                mx = max(mx, neededTime[i]);
            } else {
                ret += sm - mx;
                
                mx = sm = neededTime[i];
                
                ch = colors[i];
            }
        }

        return ret + sm - mx;
    }
};