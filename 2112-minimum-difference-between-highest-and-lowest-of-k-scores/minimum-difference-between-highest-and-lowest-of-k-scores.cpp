class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        int mini = nums[0] - nums[k - 1], n = nums.size();
        for (int i = k, j = 1; i < n; i++) {
            mini = min(mini, nums[j++] - nums[i]);
        }
        return mini;
    }
};