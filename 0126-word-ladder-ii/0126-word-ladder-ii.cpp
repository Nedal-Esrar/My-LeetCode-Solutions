class Solution {
public:
    void construct_sequences(vector<vector<string>>& res, 
                             string currentWord, 
                             string& beginWord, 
                             unordered_map<string, vector<string>> &parents, 
                             vector<string>& path) {
        if (currentWord == beginWord) {
            path.push_back(beginWord);
            
            vector<string> path_cpy(path.begin(), path.end());
            
            path.pop_back();
            
            reverse(path_cpy.begin(), path_cpy.end());
            
            res.push_back(path_cpy);
            
            return;
        }
        
        for (string word : parents[currentWord]) {
            path.push_back(currentWord);
            
            construct_sequences(res, word, beginWord, parents, path);
            
            path.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        
        unordered_map<string, vector<string>> parents;
        
        unordered_map<string, int> levels;
        
        queue<string> q;
        
        q.push(beginWord);
        
        levels[beginWord] = 0;
        
        while (!q.empty()) {
            string s = q.front();
            
            q.pop();
            
            for (int i = 0; i < s.length(); ++i) {
                string tmp = s;
                
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (s[i] == c) {
                        continue;
                    }
                    
                    tmp[i] = c;
                    
                    if (words.find(tmp) == words.end()) {
                        continue;
                    }
                    
                    if (levels[tmp] == 0 || levels[tmp] > levels[s] + 1) {
                        q.push(tmp);
                        
                        parents[tmp].clear();
                        
                        parents[tmp].push_back(s);
                        
                        levels[tmp] = levels[s] + 1;
                    } else if (levels[tmp] == levels[s] + 1) {
                        parents[tmp].push_back(s);
                    }
                }
            }
        }
        
        vector<vector<string>> res;
        
        vector<string> path;
        
        construct_sequences(res, endWord, beginWord, parents, path);
        
        return res;
    }
};