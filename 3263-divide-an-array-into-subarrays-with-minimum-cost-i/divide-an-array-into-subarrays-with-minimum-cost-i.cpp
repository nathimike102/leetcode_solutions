class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int res = nums[0];
        int mini = INT_MAX, minii = INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(nums[i] < mini){
                minii = mini;
                mini = nums[i];
            }else if(nums[i] < minii){
                minii = nums[i];
            }
        }
        return res + mini + minii;
    }
};