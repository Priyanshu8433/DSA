class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> rem(60,0);
        int cnt=0;
        for(int x: time){
            int required=60-(x%60);
            if(required==60) required=0;
            cnt+=rem[required];
            rem[x%60]++;
        }
        return cnt;
    }
};