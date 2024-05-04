class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boatCount = 0;
        
        sort(people.begin(), people.end());
        
        int l = 0;
        int r = people.size() - 1;
        
        while (l <= r) {
            if (people[l] + people[r] <= limit) {
                l++;
                r--;
            } else {
                r--;
            }
            
            ++boatCount;
        }
        
        return boatCount;
    }
};