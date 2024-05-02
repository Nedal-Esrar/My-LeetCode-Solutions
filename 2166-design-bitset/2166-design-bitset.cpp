class Bitset {
private:
    string bitset, rev_bitset;
    int c1, size;
    bool flipped;
public:
    Bitset(int size) {
        bitset = string(size, '0');
        rev_bitset = string(size, '1');
        this->size = size;
        flipped = false;
        c1 = 0;
    }
    
    void fix(int idx) {
        if (flipped) {
            if (bitset[idx] == '1') {
                --c1;
            }
            
            bitset[idx] = '0';
            
            rev_bitset[idx] = '1';
        } else {
            if (bitset[idx] == '0') {
                ++c1;
            }
            
            bitset[idx] = '1';
            
            rev_bitset[idx] = '0';
        }
    }
    
    void unfix(int idx) {
        if (flipped) {
            if (bitset[idx] == '0') {
                ++c1;
            }
            
            bitset[idx] = '1';
            
            rev_bitset[idx] = '0';
        } else {
            if (bitset[idx] == '1') {
                --c1;
            }
            
            bitset[idx] = '0';
            
            rev_bitset[idx] = '1';
        }
    }
    
    void flip() {
        flipped = !flipped;
    }
    
    bool all() {
        return count() == size;
    }
    
    bool one() {
        return count() > 0;
    }
    
    int count() {
        return flipped ? size - c1 : c1;
    }
    
    string toString() {
        return flipped ? rev_bitset : bitset;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */