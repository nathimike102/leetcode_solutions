class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n, 1), suf(n, 1);
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] * nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suf[i] = suf[i+1] * nums[i+1];
        }
        for(int i=0;i<n;i++){
            nums[i] = pref[i] * suf[i];
        }
        return nums;
    }
};