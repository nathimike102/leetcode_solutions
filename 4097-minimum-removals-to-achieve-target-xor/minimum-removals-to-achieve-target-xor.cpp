class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        int MAXX = 16384;

        vector<int> dp(MAXX, -1);
        dp[0] = 0;

        for (int num : nums) {
            vector<int> new_dp = dp;

            for (int x = 0; x < MAXX; x++) {
                if (dp[x] != -1) {
                    int nx = x ^ num;
                    new_dp[nx] = max(new_dp[nx], dp[x] + 1);
                }
            }
            dp = new_dp;
        }

        return dp[target] == -1 ? -1 : n - dp[target];
    }
};