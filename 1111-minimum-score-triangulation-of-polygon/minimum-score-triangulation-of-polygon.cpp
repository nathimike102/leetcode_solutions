class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> mini(n, vector<int>(n, 0));
        for(int i=2;i<n;i++){
            for(int j=0;j+i<n;j++){
                int m = i+j;
                int curr = 1<<30;
                for(int k=j+1;k<m;k++){
                    int score = mini[j][k] + mini[k][m] + values[j] * values[k] * values[m];
                    if(score < curr){
                        curr = score;
                    }
                }
                mini[j][m] = curr;
            }
        }
        return mini[0][n-1];
    }
};