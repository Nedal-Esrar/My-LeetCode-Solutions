class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        
        vector<pair<int, int>> diff(n);
        
        for (int i = 0; i < n; ++i) {
            diff[i].first = costs[i][1] - costs[i][0];
            diff[i].second = i;
        }
        
        sort(diff.begin(), diff.end());
        
        int ret = 0;
        
        for (int i = 0; i < n / 2; ++i) {
            ret += costs[diff[i].second][1];
        }
        
        for (int i = n / 2; i < n; ++i) {
            ret += costs[diff[i].second][0];
        }
        
        return ret;
    }
};