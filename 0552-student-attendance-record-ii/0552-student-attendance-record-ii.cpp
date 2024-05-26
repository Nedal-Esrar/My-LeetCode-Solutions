class Solution {
private:
    static const int MOD = 1e9 + 7;
    
    void set_new_state(const vector<vector<int>>& curr_dp, vector<vector<int>>& next_dp) {
        for (int total_absences = 0; total_absences < 2; ++total_absences) {
            for (int consecutive_lates = 0; consecutive_lates < 3; ++consecutive_lates) {
                next_dp[total_absences][0] = (next_dp[total_absences][0] + curr_dp[total_absences][consecutive_lates]) % MOD; // set P

                // set A
                if (total_absences < 1) {
                    next_dp[total_absences + 1][0] = (next_dp[total_absences + 1][0] + curr_dp[total_absences][consecutive_lates]) % MOD;
                }

                // set L
                if (consecutive_lates < 2) {
                    next_dp[total_absences][consecutive_lates + 1] = (next_dp[total_absences][consecutive_lates + 1] + curr_dp[total_absences][consecutive_lates]) % MOD;
                }
            }
        }
    }
public:
    int checkRecord(int n) {
        vector<vector<int>> curr_dp(2, vector<int>(3)),
                            next_dp(2, vector<int>(3));
        
        curr_dp[0][0] = 1;
        
        for (int i = 0; i < n; ++i) {
            set_new_state(curr_dp, next_dp);
            
            curr_dp = next_dp;

            next_dp = vector<vector<int>>(2, vector<int>(3));
        }
        
        int ret = 0;
        
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                ret = (ret + curr_dp[i][j]) % MOD;
            }
        }
        
        return ret;
    }
};