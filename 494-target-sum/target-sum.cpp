class Solution {
    int solve(int i, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(i>=nums.size()){
            if(target==0) return 1;
            return 0;
        }

        if(dp[i][target+2000]!=-1) return dp[i][target+2000];

        int add=solve(i+1,target-nums[i],nums,dp);
        int subtract=solve(i+1,target+nums[i],nums,dp);

        return dp[i][target+2000]=add+subtract;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(),vector<int>(4000,-1));
        return solve(0,target,nums,dp);
    }
};