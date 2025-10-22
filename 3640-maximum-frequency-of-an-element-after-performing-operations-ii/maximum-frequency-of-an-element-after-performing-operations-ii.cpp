class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int i = 0;
        int j = 0;
        unordered_map<int, int> m;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        sort(nums.begin(), nums.end());
        for (int mid = 0; mid < nums.size(); mid++) {
            while (i < nums.size() && nums[mid] - k > nums[i]) {
                i++;
            }
            while (j < nums.size() && nums[j] <= nums[mid] + k) {
                j++;
            }
            count = max(count, min(j - i, numOperations + m[nums[mid]]));
        }
        i = 0;
        j = 0;
        while (j < nums.size()) {
            while (j < nums.size() && nums[j] - nums[i] > (2 * k)) {
                i++;
            }
            count = max(count, min(j - i + 1, numOperations));
            j++;
        }
        return count;
    }
};