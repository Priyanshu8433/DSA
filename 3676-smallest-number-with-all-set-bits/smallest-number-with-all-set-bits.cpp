class Solution {
public:
    int smallestNumber(int n) {
        int x=1024;
        bool flag=false;

        while(x){
            if(x&n) flag=true;

            if(flag){
                n=(n|x);
            }
            x>>=1;
        }

        return n;
    }
};