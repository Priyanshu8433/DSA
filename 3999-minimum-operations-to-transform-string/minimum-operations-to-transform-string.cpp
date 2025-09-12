class Solution {
public:
    int minOperations(string s) {
        int mChar=123;
        for(auto ch: s){
            if(ch!='a') mChar=min(mChar,(int)ch);
            if(ch=='b') break;
        }
        return 123-mChar;
    }
};