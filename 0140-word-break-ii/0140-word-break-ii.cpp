class Solution {
private:
    void generate(int i, string& str, unordered_set<string>& words, string temp, vector<string>& ans){
        if (i == str.length()) {
            temp.pop_back();
            ans.push_back(temp);
            return;
        }

        string s;

        for(int j = i; j < str.length(); ++j) {
            s += str[j];
            
            if (words.find(s) != words.end()) {
                generate(j + 1, str, words, temp + s + ' ', ans);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(),wordDict.end());
        
        vector<string> ans;
        
        generate(0, s, words, "", ans);
        
        return ans;
    }
};