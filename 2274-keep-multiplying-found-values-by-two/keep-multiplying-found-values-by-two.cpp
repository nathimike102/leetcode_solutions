class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int, int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        while(true){
            if(mpp[original] == 0){
                return original;
            }
            original<<=1;
        }
        return 0;
    }
};