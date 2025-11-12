class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;

        for(int x: nums) if(x!=1) cnt++;
        if(cnt!=n) return cnt;
        int mini=INT_MAX;
        for(int i=0; i<n; i++){
            int gc=nums[i];
            for(int j=i+1; j<n; j++){
                gc=gcd(gc,nums[j]);
                if(gc==1){
                    mini=min(mini,j-i);
                    break;
                }
            }
        }
        if(mini==INT_MAX) return -1;
        return cnt+mini-1;
    }
};