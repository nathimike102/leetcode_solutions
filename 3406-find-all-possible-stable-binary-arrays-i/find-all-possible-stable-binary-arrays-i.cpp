class Solution {
public:
    long long MOD = 1e9 + 7;
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<int>> dp0(zero+1, vector<int>(one+1)), dp1(zero+1, vector<int>(one+1));
        for (int i = 0; i <= min(zero, limit); i++)
            dp0[i][0] = 1;
        for (int j = 0; j <= min(one, limit); j++)
            dp1[0][j] = 1;
        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                // append 0
                dp0[i][j] =
                    (0LL + dp0[i - 1][j] + dp1[i - 1][j] -
                     (i - 1 - limit >= 0 ? dp1[i - 1 - limit][j] : 0) + MOD) %
                    MOD;
                // append 1
                dp1[i][j] =
                    (0LL + dp0[i][j - 1] + dp1[i][j - 1] -
                     (j - 1 - limit >= 0 ? dp0[i][j - 1 - limit] : 0) + MOD) %
                    MOD;
            }
        }
        return (dp0[zero][one] + dp1[zero][one]) % MOD;
    }
};