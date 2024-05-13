class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ret;

        int n = nums.size();

        for (int i = 0; i < n; i++){
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int j = i + 1, k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    
                    ret.push_back(triplet);
                    
                    while (j < k && nums[j] == triplet[1]) {
                        ++j;
                    }

                    while (j < k && nums[k] == triplet[2]) {
                        --k;   
                    }
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return ret;
    }
};