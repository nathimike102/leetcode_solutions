class Solution {
public:
    #define pt pair<int, tuple<int, int, int>>
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<int> dir = {-1, 0, 1, 0, -1};
        priority_queue<pt, vector<pt>, greater<pt>> Q;
        Q.push({0, {0, 0, 2}});
        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        minTime[0][0] = 0;

        while(!Q.empty()){
            pt curr = Q.top();
            int time = curr.first;
            int x = get<0>(curr.second);
            int y = get<1>(curr.second);
            int z = get<2>(curr.second);
            Q.pop();
            if(x == n-1 && y == m-1){
                return time;
            }
            z = (z == 1? 2 : 1);
            for(int i=0;i<4;i++){
                int nx = x + dir[i];
                int ny = y + dir[i+1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    int temp = max(time + z, moveTime[nx][ny]+z); 
                    if (temp < minTime[nx][ny]) {  
                        minTime[nx][ny] = temp;  
                        Q.push({temp, {nx, ny, z}});  
                    } 
                }
            }
        }
        return 0;
    }
};