class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> Q;
        Q.push({0, 0, 0});
        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        minTime[0][0] = 0;

        while(!Q.empty()){
            auto [curr, x, y] = Q.top();
            Q.pop();
            if(x == n-1 && y == m-1){
                return curr;
            }
            for(auto d : dir){
                int nx = x + d.first;
                int ny = y + d.second;
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    int temp = max(curr + 1, moveTime[nx][ny]+1); 
                    if (temp < minTime[nx][ny]) {  
                        minTime[nx][ny] = temp;  
                        Q.push({temp, nx, ny});  
                    } 
                }
            }
        }
        return 0;
    }
};