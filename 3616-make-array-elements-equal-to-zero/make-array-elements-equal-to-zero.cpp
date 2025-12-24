class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0)
                continue;
            for (int j = 0; j < 2; ++j) {
                vector<int> arr = nums;
                int curr = i, dir = j == 0 ? -1 : 1;
                bool valid = true;
                while (curr >= 0 && curr < n) {
                    if (arr[curr] == 0) {
                        curr += dir;
                    } else {
                        arr[curr]--;
                        dir = -dir;
                        curr += dir;
                    }
                }
                for (int v : arr) {
                    if (v != 0) {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                    res++;
            }
        }
        return res;
    }
};