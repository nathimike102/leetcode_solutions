class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int total = 0, n = arr.size();
        for(int i = 0;i < n; i++){
            int left = i, right = n-i-1;
            int left_odd = (left+1)/2, left_even = (left/2)+1;
            int right_odd = (right+1)/2, right_even = (right/2)+1;
            total += arr[i] * ((left_odd * right_odd) + (left_even * right_even));
        }
        return total;
    }
};