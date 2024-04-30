class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> edges;
        
        for (auto& building : buildings) {
            edges.emplace_back(building[0], -building[2]);
            edges.emplace_back(building[1], building[2]);
        }
        
        sort(edges.begin(), edges.end());
        
        vector<vector<int>> ret;
        
        multiset<int> st{0};
        
        int y = 0;
        
        for (auto& [x, h] : edges) {
            if (h < 0) {
                st.insert(-h);
            } else {
                st.erase(st.find(h));
            }
            
            if (*st.rbegin() != y) {
                y = *st.rbegin();
                
                ret.push_back({x, y});
            }
        }
        
        return ret;
    }
};