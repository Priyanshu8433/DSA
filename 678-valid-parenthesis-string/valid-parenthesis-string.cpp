class Solution {
public:
    bool checkValidString(string s) {
        int mini=0,maxi=0;
        for(char c: s){
            if(c=='('){
                mini++;
                maxi++;
            }
            else if(c==')'){
                mini=max(0,mini-1);
                maxi--;
                if(maxi<0) return false;
            }
            else {
                mini=max(0,mini-1);
                maxi++;
            }
        }

        if(mini==0) return true;
        return false;
    }
};