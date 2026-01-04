class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int num: nums){
            int cnt=0;
            int divSum=0;
            for(int x=1; x<=num; x++){
                if(num%x==0) {
                    divSum+=x;
                    cnt++;
                }
                if(cnt>4) break;
            }
            if(cnt==4) sum+=divSum;
        }
        return sum;
    }
};