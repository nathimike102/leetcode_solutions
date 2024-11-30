class Solution {
public:
    vector<vector<int>> path;

    void dfs(int &curr, unordered_map<int, list<int>> &graph) {
        auto& neighbors = graph[curr];
        while (!neighbors.empty()) {
            int next = neighbors.front();
            neighbors.pop_front();
            dfs(next, graph);
            path.push_back({curr, next});
        }
    };
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, list<int>> graph;
        unordered_map<int, int> inOutDeg;
        for (auto& pair : pairs) {
            int start = pair[0], end = pair[1];
            graph[start].push_back(end);
            inOutDeg[start]++;
            inOutDeg[end]--;
        }
        int startNode = pairs[0][0];
        for (auto& [node, degree] : inOutDeg) {
            if (degree == 1) {
                startNode = node;
                break;
            }
        }
        dfs(startNode, graph);
        reverse(path.begin(), path.end());
        return path;
    }
};