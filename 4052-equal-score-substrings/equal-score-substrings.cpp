class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.size();
        vector<int> pre(n);
        pre[0] = s[0] - 'a' + 1;
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + (s[i] - 'a' + 1);
        }
        for (int i = 0; i < n; i++) {
            int left = pre[i];
            int right = pre[n - 1] - left;
            if (left == right)
                return true;
        }
        return false;
    }
};