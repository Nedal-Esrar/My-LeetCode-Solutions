class Solution {
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        
        vector<vector<int>> adj(n);
        
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<multiset<int>> greatest_positive(n);
        vector<multiset<int>> greatest_negative(n);
        
        dfs(0, -1, adj, greatest_positive, greatest_negative, cost);
        
        vector<long long> ans(n, 1);
        
        for (int i = 0; i < n; ++i) {
            if (greatest_positive[i].size() + greatest_negative[i].size() < 3) {
                continue;
            }
            
            vector<int> costs;
            
            for (int e : greatest_positive[i]) {
                costs.push_back(e);
            }
            
            for (int e : greatest_negative[i]) {
                costs.push_back(-e);
            }
            
            sort(costs.begin(), costs.end());
            
            int sz = costs.size();
            
            ans[i] = max({0ll,
                          1ll * costs[sz - 1] * costs[sz - 2] * costs[sz - 3],
                          1ll * costs[sz - 1] * costs[0] * costs[1]});
        }
        
        return ans;
    }
private:
    void dfs(int u, int p, vector<vector<int>>& adj, 
             vector<multiset<int>>& greatest_positive,
             vector<multiset<int>>& greatest_negative,
             vector<int>& cost) {
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            
            dfs(v, u, adj, greatest_positive, greatest_negative, cost);
            
            for (int e : greatest_positive[v]) {
                greatest_positive[u].insert(e);
            }
            
            for (int e : greatest_negative[v]) {
                greatest_negative[u].insert(e);
            }
        }
        
        if (cost[u] < 0) {
            greatest_negative[u].insert(-cost[u]);
        } else {
            greatest_positive[u].insert(cost[u]);
        }
        
        while (greatest_positive[u].size() > 3) {
            greatest_positive[u].erase(greatest_positive[u].begin());
        }
        
        while (greatest_negative[u].size() > 3) {
            greatest_negative[u].erase(greatest_negative[u].begin());
        }
    }
};