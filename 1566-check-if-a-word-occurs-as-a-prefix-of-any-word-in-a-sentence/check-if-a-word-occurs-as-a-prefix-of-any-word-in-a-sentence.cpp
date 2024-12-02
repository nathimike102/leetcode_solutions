class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string t;
        int n = searchWord.length();
        for(int i=1;ss >> t; i++){
            if(t.substr(0, n) == searchWord){
                return i;
            }
        }
        return -1;
    }
};
