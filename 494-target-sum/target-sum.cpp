class Solution {
public:
    int helper(int idx, vector<int>& nums, int target, vector<vector<int>> &dp){
        int n=nums.size();
        if(idx>=n){
            if(target==0) return 1;
            return 0;
        }

        if(dp[idx][target+2000]!=-1) return dp[idx][target+2000];

        // add to expression
        int add=helper(idx+1,nums,target-nums[idx],dp);

        // subtract from expression
        int subtract=helper(idx+1,nums,target+nums[idx],dp);

        return dp[idx][target+2000]=add+subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int m=abs(target)+sum;
        vector<vector<int>> dp(n,vector<int>(4000,-1));
        return helper(0,nums,target,dp);
    }
};