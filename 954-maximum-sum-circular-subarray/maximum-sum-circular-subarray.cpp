class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int totalSum = 0;
        int curr = 0, curr_neg = 0;
        int maxi = arr[0], mini = arr[0];
        for (int i = 0; i < arr.size(); i++) {
            //kadane's algorithm for max
            curr = max(curr + arr[i], arr[i]);
            maxi = max(maxi, curr);

            //kadane's algorithm for min
            curr_neg = min(curr_neg + arr[i], arr[i]);
            mini = min(mini, curr_neg);

            totalSum = totalSum + arr[i];
        }
        if (mini == totalSum)
            return maxi;
        return max(maxi, totalSum - mini);
    }
};