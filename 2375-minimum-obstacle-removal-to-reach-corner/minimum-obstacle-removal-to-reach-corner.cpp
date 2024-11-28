class Solution {
    #define pp pair<int, pair<int, int>>
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<int> dir = {-1, 0, 1, 0, -1};
        priority_queue<pp, vector<pp>, greater<pp>> minHeap;
        minHeap.push({0, {0, 0}});
        visited[0][0] = true;

        while(!minHeap.empty()){
            pp curr = minHeap.top();
            minHeap.pop();
            int cost = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            if(x==n-1 && y==m-1) return cost;
            for(int i=0;i<4;i++){
                int dx = x + dir[i];
                int dy = y + dir[i+1];
                if(dx >= 0 && dx < n && dy >= 0 && dy < m && !visited[dx][dy]){
                    visited[dx][dy] = true;
                    if(grid[dx][dy] == 1) minHeap.push({cost+1, {dx, dy}});
                    else minHeap.push({cost, {dx, dy}});
                }
            }
        }
        return 0; 
    }
};