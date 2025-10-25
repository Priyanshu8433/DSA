class Solution {
public:
    int totalMoney(int n) {
        int currMon=1;
        int totalSum=0;
        while(n){
            int sum=0;
            int nextDay=min(currMon+6,currMon+n-1);
            for(int i=currMon; i<=nextDay; i++) sum+=i;
            totalSum+=sum;
            n-=min(7,n);
            currMon++;
        }
        return totalSum;
    }
};