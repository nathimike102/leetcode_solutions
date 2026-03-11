class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int len = log2(n)+1;
        string bin = bitset<32>(~n).to_string().substr(32 - len);
        return bitset<32>(bin).to_ulong();
    }
};