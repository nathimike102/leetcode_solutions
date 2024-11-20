class Solution {
public:
    int takeCharacters(string s, int k) {
        int n =s.length();
        int freqa=0, freqb = 0, freqc = 0, i = 0, j = n-1;
        for(i=0;i<n;i++){
            if(freqa >= k && freqb >= k && freqc >= k){
                break;
            }
            if(s[i] == 'a') freqa++;
            else if(s[i] == 'b') freqb++;
            else if(s[i] == 'c') freqc++;
        }
        if(freqa < k || freqb < k || freqc < k){
            return -1;
        }
        int mini = i;
        i--;
        while(j>=0 && i>=0 && i<=j){
            if(s[i] == 'a') freqa--;
            else if(s[i] == 'b') freqb--;
            else if(s[i] == 'c') freqc--;
            if(freqa < k || freqb < k || freqc < k){
                if(s[j] == 'a') freqa++;
                else if(s[j] == 'b') freqb++;
                else if(s[j] == 'c') freqc++;
                j--;
            }
            if(freqa >= k && freqb >= k && freqc >= k){
                mini = min(mini, n-(j-i)-1);
            }
            i--;
        }
        return mini;
    }
};