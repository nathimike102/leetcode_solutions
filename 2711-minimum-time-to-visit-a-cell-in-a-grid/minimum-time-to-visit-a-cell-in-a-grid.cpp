class Solution {
    #define pp pair<int, pair<int, int>>
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[1][0] > 1 && grid[0][1] > 1) return -1;
        int m = grid.size(), n = grid[0].size();
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        vector<int> dir = {-1, 0, 1, 0, -1};
        vector<vector<int>> time(m, vector<int>(n, INT_MAX));
        pq.push({0, {0, 0}});
        time[0][0] = 0;
        while(!pq.empty()){
            pp curr = pq.top();
            pq.pop(); 
            int t = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            if(x == m-1 && y == n-1){
                return t;
            }
            for(int i=0;i<4;i++){
                int dx = x + dir[i];
                int dy = y + dir[i+1];
                if(dx>=0 && dx<m && dy>=0 && dy<n){
                    int w = ((grid[dx][dy]-t)&1)?0:1;
                    int nt = max(grid[dx][dy]+w, t+1);
                    if(nt < time[dx][dy]){
                        time[dx][dy] = nt;
                        pq.push({nt, {dx, dy}});
                    }
                }
            }
        }
        return -1;
    }
};