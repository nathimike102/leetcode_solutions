class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi = INT_MIN;
        int res = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > maxi){
                res = i;
                maxi = nums[i];
            }
        }
        for(int i=0;i<nums.size();i++){
            if(res != i && maxi < nums[i] * 2){
                return -1;
            }
        }
        return res;
    }
};