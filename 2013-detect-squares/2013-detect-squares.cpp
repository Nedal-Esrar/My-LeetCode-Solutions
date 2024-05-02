class DetectSquares {
private:
    map<pair<int, int>, int> pt_frq;
public:
    DetectSquares() {}
    
    void add(vector<int> point) {
        ++pt_frq[{point[0], point[1]}];
    }
    
    int count(vector<int> point) {
        int ret = 0;
        
        for (const auto& [pt, frq] : pt_frq) {
            if (pt.first != point[0] && pt.second != point[1] 
                && abs(pt.first - point[0]) == abs(pt.second - point[1])) {
                ret += frq * pt_frq[{point[0], pt.second}] * pt_frq[{pt.first, point[1]}];
            }
        }
        
        return ret;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */