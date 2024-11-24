class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        int neg = 0;
        long long maxi = 0;
        for(auto row : matrix){
            for(int i=0;i<row.size();i++){
                mini = min(mini, abs(row[i]));
                if(row[i] < 0) neg++;
                maxi += abs(row[i]);
            }
        }
        if(neg%2!=0){
            maxi -= 2*mini;
        }
        return maxi;
    }
};