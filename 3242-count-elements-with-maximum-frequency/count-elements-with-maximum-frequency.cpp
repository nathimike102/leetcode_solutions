class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxi = 0;
        map<int, int> mpp;
        for(int num : nums){
            mpp[num]++;
            maxi = max(maxi, mpp[num]);
        }
        int res = 0;
        for(auto &mp : mpp){
            if(mp.second == maxi) res += maxi;
        }
        return res;
    }
};