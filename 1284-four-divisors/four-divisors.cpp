class Solution {
public:
    int solve(int n){
        int cnt=0;
        int sum=0;
        // cout<<"For:"<<n<<endl;
        for(int i=1; i*i<=n; i++){
            if(n%i==0){
                int sec=n/i;
                if(sec==i){
                    cnt+=1;
                    sum+=i;
                }
                else{
                    cnt+=2;
                    sum+=i+sec;
                }
            }
            if(cnt>4) return 0;
        }
        if(cnt==4){
            return sum;
        }
        return 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int num: nums){
            sum+=solve(num);
        }
        return sum;
    }
};