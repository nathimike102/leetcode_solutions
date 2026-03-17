class Solution {
public:
    long long min(long long a, long long b){
        if(a < b) return a;
        return b;
    }
    long long countCommas(long long n) {
        long long res = 0;
        if(n>=1e3){
            res += min(n, 1e6) - 1e3 + 1;
        }
        if(n>=1e6){
            res += 2*(min(n, 1e9) - 1e6) + 1;
        }
        if(n>=1e9){
            res += 3*(min(n, 1e12) - 1e9) + 1;
        }
        if(n>=1e12){
            res += 4*(min(n, 1e15) - 1e12) + 1;
        }
        if(n>=1e15){
            res += 5*(min(n, 1e18) - 1e15) + 1;
        }
        return res;
    }
};