class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int, int> mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(mpp[arr[i]*2] > 0){
                if(arr[i] == 0 && mpp[arr[i]] == 1) continue;
                return true;
            }
        }
        return false;
    }
};