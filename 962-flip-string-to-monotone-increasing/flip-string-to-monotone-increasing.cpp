class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int res = 0, count_one = 0;
        for(char ch : s){
            if(ch == '1') count_one++;
            else res = min(res+1, count_one);
        }
        return res;
    }
};