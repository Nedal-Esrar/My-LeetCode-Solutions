class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev_count = 0;
	
        int ret = 0;

        for (const string& row : bank) {
            int count = count_ones(row);

            ret += count * prev_count;

            if (count != 0) {
                prev_count = count;
            }
        }

        return ret;
    }
private:
    int count_ones(const string& s) {
        int ret =0 ;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                ++ret;
            }
        }

        return ret;
    }
};