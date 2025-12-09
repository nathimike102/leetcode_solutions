class Solution {
public:
    int attacks(int p1, int p2, vector<vector<char>>& b){
        int count = 0;
        //up
        for(int i=p1; i >= 0; i--){
            if(b[i][p2] == 'B'){
                break;
            }
            if(b[i][p2] == 'p'){
                count++;
                break;
            }
        }
        //down
        for(int i=p1; i < 8; i++){
            if(b[i][p2] == 'B'){
                break;
            }
            if(b[i][p2] == 'p'){
                count++;
                break;
            }
        }
        //left
        for(int i=p2; i >= 0; i--){
            if(b[p1][i] == 'B'){
                break;
            }
            if(b[p1][i] == 'p'){
                count++;
                break;
            }
        }
        //right
        for(int i=p2; i < 8; i++){
            if(b[p1][i] == 'B'){
                break;
            }
            if(b[p1][i] == 'p'){
                count++;
                break;
            }
        }
        return count;
    }
    int numRookCaptures(vector<vector<char>>& board) {
        int count = 0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j] == 'R'){
                    count = attacks(i, j, board);
                }
            }
        }
        return count;
    }
};