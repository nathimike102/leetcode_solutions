class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        for (int i = 0; i < nums.size(); i++) {
            if(i == 0){
                temp.push_back(nums[i]);
            }
            else {
                if(nums[i] > temp.back()){
                    temp.push_back(nums[i]);
                }
                else{
                    int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                    temp[idx] = nums[i];
                }
            }
        }
        return temp.size();
    }
};