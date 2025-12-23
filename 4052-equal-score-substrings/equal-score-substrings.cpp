class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.size();
        int left = 0, total = 0;
        for (int i = 0; i < n; i++) {
            total += (s[i] - 'a' + 1);
        }
        for (int i = 0; i < n; i++) {
            left += (s[i] - 'a' + 1);
            int right = total - left;
            if (left == right)
                return true;
        }
        return false;
    }
};