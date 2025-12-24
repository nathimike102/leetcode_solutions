class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int>());
        int i=0, res =0;
        while(total > 0){
            res++;
            total -= capacity[i++];
        }
        return res;
    }
};