class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int right = 0, dash = 0;
        for(char ch : moves){
            if(ch == 'L'){
                right--;
            }else if(ch == 'R'){
                right++;
            }else{
                dash++;
            }
        }
        return abs(right) + dash;
    }
};