class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int num : nums){
            string str = to_string(num);
            int len = str.length();
            if(len%2==0) count++;
        }
        return count;
    }
};