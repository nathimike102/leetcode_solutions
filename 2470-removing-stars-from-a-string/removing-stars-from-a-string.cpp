class Solution {
public:
    string removeStars(string s) {
        string str;
        for(char ch : s){
            if(ch == '*'){
                str.pop_back();
            }else{
                str.push_back(ch);
            }
        }
        return str;
    }
};