class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int m = mat.size(), n = mat[0].size();
        int i = 0, j = 0;
        for(int d=0;d<m+n-1;d++){
            int x = i, y= j;
            vector<int> odds;
            while(x >= 0 && y < n){    
                if(d%2==0){
                    res.push_back(mat[x][y]);
                }else{
                    odds.push_back(mat[x][y]);
                }
                x--;
                y++;
            }
            reverse(odds.begin(), odds.end());
            for(int k=0;k<odds.size();k++){
                res.push_back(odds[k]);
            }
            if(i<m-1){
                i++;
            }else if(j<n-1){
                j++;
            }else{
                break;
            }
        }
        return res;
    }
};