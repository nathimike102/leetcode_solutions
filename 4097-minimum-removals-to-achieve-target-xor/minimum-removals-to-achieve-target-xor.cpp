class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        for (int x : nums)
            target ^= x;

        int maxi = 1 << 14;
        vector<int> dp(maxi, INT_MAX);
        dp[0] = 0;

        for (int x : nums) {
            for (int i = 0; i < maxi; i++) {
                int j = i ^ x;
                if (i > j)
                    continue;
                if (dp[j] != INT_MAX)
                    dp[i] = min(dp[i], dp[j] + 1);
                if (dp[i] != INT_MAX)
                    dp[j] = min(dp[j], dp[i] + 1);
            }
        }

        return dp[target] == INT_MAX ? -1 : dp[target];
    }
};