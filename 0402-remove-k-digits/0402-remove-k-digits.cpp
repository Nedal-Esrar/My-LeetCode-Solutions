class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.length() == k) {
            return "0";
        }

        string ans;
        
        vector<char> stk;
        
        for (char c : num) {
            while (k > 0 && !stk.empty() && stk.back() > c) {
                stk.pop_back();
                --k;
            }
            
            stk.push_back(c);
        }
        
        
        while (k-- > 0) {
            stk.pop_back();
        }

        for (char c : stk) {
            if (c == '0' && ans.empty()) {
                continue;
            }
            
            ans += c;
        }

        return ans.empty() ? "0" : ans;
    }
};