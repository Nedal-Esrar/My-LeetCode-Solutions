class Solution {
public:
    int lengthLongestPath(string input) {
        stringstream ss(input);
        
        string token;
        
        int ret = 0;
        
        stack<pair<int, int>> stk; // (len, # of tabs)
        stk.push({0, -1});
        
        while (getline(ss, token, '\n')) {
            int num_tabs = 0;
            
            while (token[num_tabs] == '\t') {
                ++num_tabs;
            }
            
            while (stk.top().second >= num_tabs) {
                stk.pop();
            }
            
            int len = stk.top().first + token.length() - num_tabs;
            
            if (token.find('.') != string::npos) {
                ret = max(ret, len + (int)stk.size() - 1);
            }
            
            stk.push({len, num_tabs});
        }
        
        return ret;
    }
};