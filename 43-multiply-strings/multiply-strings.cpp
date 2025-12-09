class Solution {
public:
    string mul(int x, string num1, int n){
        int curr = 0;
        reverse(num1.begin(), num1.end());
        for(int i=0;i<num1.size();i++){
            int val = (num1[i]-'0') * x + curr;
            num1[i] = val%10 + '0';
            curr = val/10;
        }
        if(curr) num1 += (curr + '0');
        reverse(num1.begin(), num1.end());
        for(int i=0;i<n;i++){
            num1+='0';
        }
        return num1;
    }
    string add(string str1, string str2){
        int curr = 0;
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());
        int i;
        for(i=0;i<str1.length();i++){
            int val = (str1[i] - '0') + (str2[i] - '0') + curr;
            str2[i] = val%10 + '0';
            curr = val/10;
        }
        for(i;i<str2.length();i++){
            int val = curr + (str2[i] - '0');
            str2[i] = val%10 + '0';
            curr = val/10;
        }
        if(curr) str2 += (curr+ '0');
        reverse(str2.begin(), str2.end());
        return str2;
    }
    string multiply(string num1, string num2) {
        string str = "";
        int n = num2.length();
        reverse(num2.begin(), num2.end());
        for(int i=0;i<n;i++){
            int x = num2[i] - '0';
            string temp = mul(x, num1, i);
            str = add(str, temp);
        }
        if(str[0] == '0') str = '0';
        return str;
    }
};