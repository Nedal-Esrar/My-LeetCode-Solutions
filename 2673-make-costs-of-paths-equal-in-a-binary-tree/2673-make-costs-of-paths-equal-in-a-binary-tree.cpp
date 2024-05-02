class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int idx = n - 1;
        
        int ans = 0;
        
        while (idx >= 2) {
            int parent_idx = idx / 2 - 1;
            
            cost[parent_idx] += max(cost[idx], cost[idx - 1]);
            
            ans += abs(cost[idx] - cost[idx - 1]);
            
            idx -= 2;
        }
        
        return ans;
    }
    
    
};