class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> str(n);
        return str.count();
    }
};