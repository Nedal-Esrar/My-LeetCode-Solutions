class Solution {
private:
    bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int ret = 0;
        
        for (int i = left; i <= right; ++i) {
            if (is_vowel(words[i].front()) && is_vowel(words[i].back())) {
                ++ret;
            }
        }
        
        return ret;
    }
};