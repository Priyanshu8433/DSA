class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        int n=nums.size();
        long long total=0;
        sort(nums.begin(),nums.end());
        int prev=0;

        for(int i=0; i<n; i++){
            int interval=min(nums[i]-prev-1,k);
            int curr=prev+interval;
            if(interval>0){
                long long prevSum=1ll*prev*(prev+1)/2;
                long long currSum=1ll*curr*(curr+1)/2;
                long long sum=currSum-prevSum;

                total+=sum;
                k-=interval;
            }
            prev=nums[i];
        }

        if(k){
            int prev=nums.back();
            int curr=prev+k;
            long long prevSum=1ll*prev*(prev+1)/2;
            long long currSum=1ll*curr*(curr+1)/2;
            long long sum=currSum-prevSum;

            total+=sum;
        }

        return total;
    }
};