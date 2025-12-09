class Solution {
public:
    string get_min(string s){
        stack<char> st;
        for(char ch : s){
            if(ch == '#'){
                if(!st.empty()) st.pop();
            }else{
                st.push(ch);
            }
        }
        string str;
        while(!st.empty()){
            str = st.top() + str;
            st.pop();
        }
        return str;
    }
    bool backspaceCompare(string s, string t) {
        string str1 = get_min(s), str2 = get_min(t);
        return str1 == str2;
    }
};