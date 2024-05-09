class DSU {
private:
    vector<int> leader;
    vector<int> size;
    
public:
    DSU(int n) {
        leader.resize(n);
        
        for (int i = 0; i < n; ++i) {
            leader[i] = i;
        }
        
        size.resize(n, 1);
    }
    
    int get_leader(int u) {
        if (u == leader[u]) {
            return u;
        }
        
        return leader[u] = get_leader(leader[u]);
    }
    
    void join(int u, int v) {
        u = get_leader(u);
        v = get_leader(v);
        
        if (u == v) {
            return;
        }
        
        if (size[u] < size[v]) {
            swap(u, v);
        }
        
        size[u] += size[v];
        leader[v] = u;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        /*
            define a DSU structure
            and link edges one by one
            if one of the edges links two nodes that are already in the same component
            then this is the intended edge.
        */
        
        int n = edges.size(); // n is the number of nodes (in a tree it is # of edges - 1 but here an additional one exists)
        
        DSU dsu(n);
        
        for (const vector<int>& edge : edges) {
            if (dsu.get_leader(edge[0] - 1) == dsu.get_leader(edge[1] - 1)) {
                return edge;
            }
            
            dsu.join(edge[0] - 1, edge[1] - 1);
        }
        
        return {-1, -1};
    }
};