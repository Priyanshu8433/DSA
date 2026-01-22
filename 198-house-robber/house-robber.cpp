class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        for(int i=1; i<n; i++){
            // rob
            int loot=nums[i];
            if(i>1) loot+=dp[i-2];
            // not rob
            int notLoot=dp[i-1];

            dp[i]=max(loot,notLoot);
        }
        return max(dp[n-1],dp[n-2]);
    }
};