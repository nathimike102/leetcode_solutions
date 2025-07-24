class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; ++i) {
            int comp = target - nums[i];
            if (mpp.count(comp)) {
                return {mpp[comp], i};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};        