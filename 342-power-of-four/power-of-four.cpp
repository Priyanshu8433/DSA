class Solution {
public:
    bool isPowerOfFour(int n) {
        int prod=1;
        while(prod<=n){
            if(prod==n) return true;
            if(INT_MAX/4<prod) return false;
            prod*=4;
        }
        return false;
    }
};