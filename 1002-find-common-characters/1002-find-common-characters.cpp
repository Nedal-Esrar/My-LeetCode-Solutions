class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> result = count_frq(words[0]);
        
        for (int i = 1; i < words.size(); ++i) {
            vector<int> cur_frq = count_frq(words[i]);
            
            accumulate_result(result, cur_frq);
        }
        
        return construct_return_result(result);
    }
    
private:
    vector<int> count_frq(string word) {
        vector<int> frq(26);
        
        for (char c : word) {
            ++frq[c - 'a'];
        }
        
        return frq;
    }
    
    void accumulate_result(vector<int>& result, const vector<int>& cur) {
        for (int i = 0; i < 26; ++i) {
            result[i] = min(result[i], cur[i]);
        }
    }
    
    vector<string> construct_return_result(const vector<int>& result) {
        vector<string> ret;
        
        for (int i = 0; i < 26; ++i) {
            string to_add(1, char(i + 'a'));
            
            for (int j = 0; j < result[i]; ++j) {
                ret.push_back(to_add);
            }
        }
        
        return ret;
    }
};