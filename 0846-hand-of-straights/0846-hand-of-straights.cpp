class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        
        if (n % groupSize != 0) {
            return false;
        }
        
        map<int, int> frq;
        
        for (int card : hand) {
            ++frq[card];
        }
        
        while (frq.size() > 0) {
            int start = frq.begin()->first;
            
            int end = start + groupSize;
            
            for (int i = start; i < end; ++i) {
                if (frq.find(i) == frq.end()) {
                    return false;
                }
                
                if (--frq[i] == 0) {
                    frq.erase(i);   
                }
            }
        }
        
        return true;
    }
};