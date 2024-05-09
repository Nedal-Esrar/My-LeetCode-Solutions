class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        /*
            The idea for the solution is
            start from the last, maintain an array that stores the following:
            for a bit i, store the last number examined so far where it contains that bit
            then, in each iteration, get the maximum index (where from the current index and that index, it is                     guaranteed that all of the bits examined so far exist (and therefore the interval has the maximum OR))
            from that array and calculate the length of the interval achieved.
        */
        
        int n = nums.size();
        
        vector<int> ans(n);
        
        vector<int> dp(30); // at most 30 bits in non-negative numbers up to 1e9 
        
        for (int i = n - 1; i > -1; --i) {
            for (int j = 0; j < 30; ++j) {
                if (nums[i] >> j & 1) {
                    dp[j] = i;
                }
            }
            
            int mx = *max_element(dp.begin(), dp.end());
            
            ans[i] = max(1, mx - i + 1);
        }
        
        return ans;
    }
};