class Solution {
public:
    int solve(int idx, vector<int> &nums, int n,vector<int> &dp){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];

        int loot=solve(idx+2,nums,n,dp)+nums[idx];
        int notLoot=solve(idx+1,nums,n,dp);

        return dp[idx]=max(loot,notLoot);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(0,nums,nums.size(),dp);
    }
};