class Solution {
public:
    void do_swap(vector<int> &arr){
        int n = arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]%2 == arr[j]%2 && arr[j] > arr[i]){
                    swap(arr[i], arr[j]);
                }    
            }
        }
    }
    int largestInteger(int num) {
        long long res = 0;
        vector<int> arr;
        while(num){
            arr.push_back(num%10);
            num/=10;
        }
        reverse(arr.begin(), arr.end());
        do_swap(arr);
        for(int i=0;i<arr.size();i++){
            res = res*10 + arr[i];
        }
        return res;
    }
};