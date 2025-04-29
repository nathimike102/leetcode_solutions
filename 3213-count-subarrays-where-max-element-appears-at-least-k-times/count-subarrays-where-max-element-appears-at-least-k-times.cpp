class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        long long res = 0, j = 0;
        int maxEle = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == maxi){
                maxEle++;
            }
            while(maxEle == k){
                if(nums[j] == maxi){
                    maxEle--;
                }
                j++;
            }
            res+=j;
        }
        return res;
    }
};