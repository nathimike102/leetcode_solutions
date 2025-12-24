class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int sofar = 0;
        int ans = 0;
        for (const int& num: nums) {
            if (num == 0) {
                if (sofar == (sum - sofar)) ans += 2;
                else if (abs(sum - 2 * sofar) == 1) ans += 1;
            } else sofar += num;
            if (sofar * 2 - 1 > sum) break;
        }
        return ans;
    }
};