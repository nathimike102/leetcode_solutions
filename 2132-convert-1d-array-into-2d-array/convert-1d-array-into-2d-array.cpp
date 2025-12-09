class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int k =  original.size();
        vector<vector<int>> res;
        if(k != m*n) return res;
        vector<int> temp(n);
        for(int i=0, j=0;i<k;i++){
            temp[j++] = original[i];
            if(j == n){
                res.push_back(temp);
                j=0;
            }
        }
        return res;
    }
};