class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        int res = 1<<k;
        set<string> st;
        string str = "";
        if(n<k) return false;
        for(int i =0;i<k;i++){
            str+=s[i];
        }
        st.insert(str);
        for(int i=k;i<n;i++){
            str+=s[i];
            // erase(str.begin(), str.begin()+1);
            str = str.substr(1);
            st.insert(str);
        }
        cout<<res<<" "<<st.size();
        return (st.size() == res);
    }
};