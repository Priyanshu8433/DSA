class Solution {
public:
    int minOperations(string s) {
        int mChar=123;

        for(auto ch: s){
            if(ch!='a') mChar=min(mChar,(int)ch);
        }
        return 123-mChar;
    }
};