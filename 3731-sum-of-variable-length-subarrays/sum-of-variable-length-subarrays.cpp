class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int total = 0, n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
        }
        for(int i=0;i<n;i++){
            int left = max(0, i-nums[i]);
            if(left == 0) total += pre[i];
            else total += pre[i] - pre[left-1];
        }
        return total;
    }
};