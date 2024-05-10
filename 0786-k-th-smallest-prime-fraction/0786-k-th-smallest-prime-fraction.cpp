class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        
        double left = 0, right = 1.0;
        
        while (left < right){
            double mid = (left + right) / 2;
            
            double maxFraction = 0.0;
            
            int totalSmallerFractions = 0, numeratorIdx = 0, denominatorIdx = 0;
            
            int j = 1;
            
            for (int i = 0; i < n - 1; ++i){
                while (j < n && arr[i] >= mid * arr[j]){
                    j++;
                }

                totalSmallerFractions += (n - j);
                
                if (j == n) {
                    break;
                }
                
                double fraction = static_cast<double>(arr[i]) / arr[j];
                
                if (fraction > maxFraction) {
                  numeratorIdx = i;
                  denominatorIdx = j;
                  maxFraction = fraction;
                }
            }
            
            if (totalSmallerFractions == k) {
                return {arr[numeratorIdx], arr[denominatorIdx]};
            } else if (totalSmallerFractions > k) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        return {};
    }
};