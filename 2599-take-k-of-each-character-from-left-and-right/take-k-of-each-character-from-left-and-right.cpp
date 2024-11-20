class Solution {
public:
    int takeCharacters(string s, int k) {
        int n =s.length();
        int freq[3] = {0}, i = 0, j = n-1;
        for(i=0;i<n;i++){
            if(freq[0] >= k && freq[1] >= k && freq[2] >= k){
                break;
            }
            freq[s[i]-'a']++;
        }
        if(freq[0] < k || freq[1] < k || freq[2] < k){
            return -1;
        }
        int mini = i--;
        while(j>=0 && i>=0 && i<=j){
            freq[s[i]-'a']--;
            i--;
            if(freq[0] < k || freq[1] < k || freq[2] < k){
                freq[s[j]-'a']++;
                j--;
            }
            if(freq[0] >= k && freq[1] >= k && freq[2] >= k){
                mini = min(mini, n-(j-i));
            }
        }
        return mini;
    }
};