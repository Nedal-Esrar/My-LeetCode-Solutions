class Solution {
public:
    int passThePillow(int n, int time) {
        int turns = time / (n - 1);
        
        time %= n - 1;
        
        return turns % 2 == 0 ? time + 1 : n - time;
    }
};