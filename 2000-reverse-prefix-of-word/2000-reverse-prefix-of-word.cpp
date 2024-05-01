class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        
        int ch_pos = word.find(ch);
        
        reverse(word.begin(), word.begin() + ch_pos + 1);
        
        return word;
    }
};