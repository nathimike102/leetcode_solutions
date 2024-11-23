class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> res(m, vector<char> (n, '.'));
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<m;j++){
                if(box[i][j] == '#'){
                    count++;
                }
                else if(box[i][j] == '*'){
                    res[j][n-1-i] = '*';
                    while(count){
                        res[j-count][n-i-1]='#';
                        count--;
                    }
                }
            }
            while(count){
                res[m-count][n-1-i] = '#';
                count--;
            }
        }
        return res;
    }
};