class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX, neg = 0, n = matrix.size();
        long long maxi = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] < 0){
                    neg++;
                    matrix[i][j] *= -1;
                }
                mini = min(mini, matrix[i][j]);
                maxi += matrix[i][j];
            }
        }
        if (neg % 2 != 0)
            maxi -= 2 * mini;
        return maxi;
    }
};