class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> res(m, vector<int>(n , 0));
        for(auto p : indices){
            int i = p[0], j = p[1];
            for(int r=0;r<m;r++){
                res[r][j]++;
            }
            for(int c=0;c<n;c++){
                res[i][c]++;
            }
        }
        int count = 0;
        for(auto p : res){
            for(int num : p){
                if(num%2!=0) count++;
            }
        }
        return count;
    }
};