class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for (char c : s) {
            ++mp[c];
        }

        int cnt = 0;

        bool odd = 0;

        for (auto& [f, s] : mp) {
            cnt += s - s % 2;
            odd |= s % 2;
        }

        return cnt + odd;
    }
};