class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX, neg = 0, n = matrix.size();
        long long maxi = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                mini = min(mini, abs(matrix[i][j]));
                if (matrix[i][j] < 0)
                    neg++;
                maxi += abs(matrix[i][j]);
            }
        }
        if (neg % 2 != 0)
            maxi -= 2 * mini;
        return maxi;
    }
};