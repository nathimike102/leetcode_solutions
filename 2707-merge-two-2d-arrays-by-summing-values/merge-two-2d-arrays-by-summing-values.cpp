class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;

        vector<vector<int>> mergedArray;
        while (i < n && j < m) {
            if (nums1[i][0] == nums2[j][0]) {
                mergedArray.push_back(
                    {nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            } else if (nums1[i][0] < nums2[j][0]) {
                mergedArray.push_back(nums1[i]);
                i++;
            } else {
                mergedArray.push_back(nums2[j]);
                j++;
            }
        }
        while (i < n) {
            mergedArray.push_back(nums1[i]);
            i++;
        }
        while (j < m) {
            mergedArray.push_back(nums2[j]);
            j++;
        }

        return mergedArray;
    }
};