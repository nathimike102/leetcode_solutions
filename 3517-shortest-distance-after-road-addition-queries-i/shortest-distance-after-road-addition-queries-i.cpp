class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) { 
        vector<vector<int>> graph(n);  
        for (int i = 0; i < n - 1; ++i) {  
            graph[i].push_back(i + 1);  
        }  
        
        vector<int> res;  
        
        for (int i=0;i<queries.size();i++) {  
            int x = queries[i][0];  
            int y = queries[i][1];  
            graph[x].push_back(y);
            
            vector<int> dis(n, INT_MAX);  
            dis[0] = 0;  
            queue<int> q;  
            q.push(0);  
            
            while (!q.empty()) {  
                int cur = q.front();  
                q.pop();  
                
                for (int neighbor : graph[cur]) {  
                    if (dis[cur] + 1 < dis[neighbor]) {  
                        dis[neighbor] = dis[cur] + 1;  
                        q.push(neighbor);  
                    }  
                }  
            }  
            
            res.push_back(dis[n - 1] == INT_MAX ? -1 : dis[n - 1]);  
        }  
        return res;
    }
};