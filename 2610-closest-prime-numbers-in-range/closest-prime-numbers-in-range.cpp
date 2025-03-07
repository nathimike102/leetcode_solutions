class Solution {
public:
    bool isPrime(int n) {
        if(n < 2) return false;
        if(n == 2 || n == 3 || n == 5) return true;
        if(n%2==0 || n%3 == 0) return false;
        for(int i=5;i*i<=n;i+=6){
            if(n%i==0 || n%(i+2)==0) return false;
        }
        return true;
    }
    
    vector<int> closestPrimes(int left, int right) {
        int prevPrime = -1, res1 = -1, res2 = -1;
        int minDiff = 1e6;
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                if (prevPrime != -1) {
                    int diff = i - prevPrime;
                    if (diff < minDiff) {
                        minDiff = diff;
                        res1 = prevPrime;
                        res2 = i;
                    }
                    if (diff == 2 or diff == 1)
                        return {prevPrime, i};
                }
                prevPrime = i;
            }
        }
        if(res1 == -1) return {-1, -1};
        return {res1, res2};
    }
};