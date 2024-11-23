class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        for(int i =0;i<n;i++){
            int count = 0;
            for(int j=0;j<m;j++){
                if(box[i][j] == '#'){
                    count++;
                    box[i][j] = '.';
                }
                else if(box[i][j] == '*'){
                    while(count>0){
                        box[i][j-count]='#';
                        count--;
                    }
                }
            }
            while(count>0){
                box[i][m-count] = '#';
                count--;
            }
        }
        vector<vector<char>> res(m, vector<char> (n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[j][i] = box[n-i-1][j];
            }
        }
        return res;
    }
};