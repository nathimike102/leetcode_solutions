class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for(int i=3; i<=n-2;i++){
            for(int j=i+1; j<=n-1;j++){
                int c_s = i*i + j*j;
                if(sqrt(c_s) == floor(sqrt(c_s)) && sqrt(c_s) <= n){
                    count+=2;
                } 
            }
        }
        return count;
    }
};