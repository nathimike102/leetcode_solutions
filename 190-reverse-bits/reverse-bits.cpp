class Solution {
public:
    int reverseBits(int n) {
        long long ans = 0;
        int i = 31;
        while(n){
            int rem = n%2;
            n/=2;
            if (rem) ans += pow(2, i);
            i--;
        }
        return ans;
    }
};