class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> arr(10001);
        for(int i=0; i<banned.size(); i++){
            arr[banned[i]]=1;
        }
        long sum=0;
        int cnt=0;
        for(int i=1; i<=n; i++){
            if(arr[i]==1){continue;}
            sum+=i;
            if(sum>maxSum){
               break;
            }
            cnt++;
        }
        return cnt;
    }
};