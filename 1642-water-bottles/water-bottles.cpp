class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drank = 0, empty = 0;
        while(numBottles + empty>= numExchange){
            drank += numBottles;
            empty += numBottles % numExchange;
            numBottles /= numExchange;
            if(empty>=numExchange){
                numBottles+=(empty/numExchange);
                empty%=numExchange;
            }
            cout<<numBottles<<empty<<" ";
        }
        return drank+numBottles;
    }
};