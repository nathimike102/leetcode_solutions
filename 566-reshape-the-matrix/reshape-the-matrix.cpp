class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();
        if(r > n*m) return mat;
        c = (n*m) / r;
        if(c*r != n*m) return mat;
        vector<vector<int>> res(r, vector<int>(c, 0));
        int a = 0, b = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[a][b++] = mat[i][j];
                if(b == c){
                    a++;
                    b=0;
                }
            }
        }
        return res;
    }
};