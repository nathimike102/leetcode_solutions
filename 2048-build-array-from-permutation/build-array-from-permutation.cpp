class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> arr;
        for(int num : nums){
            arr.push_back(nums[num]);
        }
        return arr;
    }
};