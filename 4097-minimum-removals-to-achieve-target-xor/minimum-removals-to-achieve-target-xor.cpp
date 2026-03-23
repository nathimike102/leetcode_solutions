class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = 0;
        for (int num : nums) {
            auto mpp1 = mpp;
            for (auto& [res, len] : mpp) {
                int x = res ^ num;
                if (!mpp1.count(x)) {
                    mpp1[x] = len + 1;
                } else {
                    mpp1[x] = max(mpp1[x], len + 1);
                }
            }
            mpp = mpp1;
        }
        if (!mpp.count(target))
            return -1;
        return n - mpp[target];
    }
};