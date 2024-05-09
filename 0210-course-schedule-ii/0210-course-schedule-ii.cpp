class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            This problem can be solved using topological sorting
            start by taking all course that has no prerequisits (for this problem this means that no edge going out of             it) and progress to the courses that has 1 prerequisit being one of them and so on.
            if the process is finished with all of the courses being taken, then return the result list,
            else return an empty list.
        */
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        
        // construct an adjancency list from the list of edges being passed.
        for (const vector<int>& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]); // reversed the edge to make work easy ;)
            
            ++indegree[edge[0]];
        }
        
        queue<int> q;
        
        vector<int> ans;
        
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] != 0) {
                continue;
            }
            
            q.push(i);
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            ans.push_back(u);
            
            for (int v : adj[u]) {
                if (--indegree[v] == 0) { // no prerequisites remaining
                    q.push(v);
                }
            }
        }
        
        return ans.size() == numCourses ? ans : vector<int>();
    }
};