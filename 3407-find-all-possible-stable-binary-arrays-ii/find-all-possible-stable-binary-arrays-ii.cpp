class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int mod = 1'000'000'007;
        int L = limit + 1;

        // Swapping 0 and 1 doesn't change the count, but can reduce memory (O(one*L))
        if (one > zero) swap(zero, one);

        // First row
        vector<int> dp0_prev(one + 1, 0), dp1_prev(one + 1, 0);
        for (int j = 1; j <= min(one, limit); ++j) dp1_prev[j] = 1;

        // Store last L = limit + 1 dp1 rows to access dp1[i-L][j]
        deque<vector<int>> dp1q;
        dp1q.push_back(dp1_prev);

        for (int i = 1; i <= zero; ++i) {
            vector<int> dp0(one + 1, 0), dp1(one + 1, 0);
            if (i <= limit) 
                dp0[0] = 1;

            for (int j = 1; j <= one; ++j) {
                dp0[j] = (dp0_prev[j] + dp1_prev[j] - (i >= L ? dp1q.front()[j] : 0)) % mod;
                dp1[j] = (dp1[j - 1] + dp0[j - 1] - (j >= L ? dp0[j - L] : 0)) % mod;

                // Fix negatives
                dp0[j] = (dp0[j] + mod) % mod;
                dp1[j] = (dp1[j] + mod) % mod;
            }

            dp1q.push_back(dp1);
            if (dp1q.size() > L) 
                dp1q.pop_front();

            dp0_prev.swap(dp0);
            dp1_prev.swap(dp1);
        }

        return (dp0_prev[one] + dp1_prev[one]) % mod;
    }
};