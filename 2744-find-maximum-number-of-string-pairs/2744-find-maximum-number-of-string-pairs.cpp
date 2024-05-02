class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, int> frq;
        
        int ans = 0;
        
        for (const string& word : words) {
            string reversed = word;
            reverse(reversed.begin(), reversed.end());
            
            if (frq.find(reversed) == frq.end()) {
                ++frq[word];
            } else {
                ++ans;
                
                if (--frq[word] == 0) {
                    frq.erase(word);
                }
            }
        }
        
        return ans;
    }
};