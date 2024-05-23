class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> v;

        solve(0, s, v ,ret);

        return ret;
    }

    void solve(int i, const string& s, vector<string>& v, vector<vector<string>>& ret) {
        if (i == s.length()) {
            ret.push_back(v);
            return;
        }

        for (int j = i; j < s.length(); ++j) {
            if (palindrome(s, i, j)) {
                v.push_back(s.substr(i, j - i + 1));
                solve(j + 1, s, v, ret);
                v.pop_back();
            }
        }
    }

    bool palindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }

            ++i;
            --j;
        }

        return true;
    }
};