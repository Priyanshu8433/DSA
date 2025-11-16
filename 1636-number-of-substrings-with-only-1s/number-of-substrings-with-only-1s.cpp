class Solution {
public:
    int numSub(string s) {
        int cnt=0;
        long long result=0;
        int MOD=1e9+7;
        for(char c: s){
            if(c=='1') cnt++;
            else cnt=0;
            result+=(cnt%MOD);
        }
        return result%MOD;
    }
};