class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<int, int> frq;
        
        for (char c : suits) {
            ++frq[c - 'a'];
        }
        
        if (frq.size() == 1) {
            return "Flush";
        }
        
        frq.clear();
        
        for (int rank : ranks) {
            ++frq[rank];
        }

        if (frq.size() == 5) {
            return "High Card";
        }
        
        for (auto& [_, f] : frq) {
            if (f >= 3) {
                return "Three of a Kind";
            }
        }
        
        return "Pair";
    }
};