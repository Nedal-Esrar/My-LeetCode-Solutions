class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        /*
            Given the constraints of the problem, we can say the following:
            for an element at index i:
                if the element is less than its left neighbour, then the array's left subsegment will have a peak element, because there is a rising edge that will either continue to rise, or decrease at some point.
                the same can be said if the right neighbour is greater than the element at i with direction difference.
                
            using this information, we can run a binary search to check these condition and divide the search space accordingly, this will O(log2(n)) T.C. where n is the size of the array nums.
        */
        
        int n = nums.size();
        
        int l = 0, r = n - 1;
        
        while (l <= r) {
            int md = l + (r - l) / 2;
            
            if (md > 0 && nums[md] < nums[md - 1]) {
                r = md - 1;
            } else if (md < n - 1 && nums[md] < nums[md + 1]) {
                l = md + 1;
            } else {
                return md;
            }
        }
        
        return -1;
    }
};