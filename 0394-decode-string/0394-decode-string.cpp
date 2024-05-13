class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        
        stack<int> no_st;
        
        string result = "";
        
        int num = 0 ; 
        
        for(char c : s) {
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            } else if (isalpha(c)) {
                result += c;
            } else if(c == '[') {
                st.push(result);
                
                no_st.push(num);
                
                result = "";
                
                num = 0;
            } else if(c == ']') {
                int prev_n = no_st.top();
                no_st.pop();
                
                string prev_str = st.top();  
                st.pop();
                
                for(int i = 0; i < prev_n; ++i) {
                    prev_str += result;
                } 
                
                result = prev_str;
            }
        }
        
        return result;
    }
};