class Solution {
public:
    bool helper(int idx, vector<int>&nums, int target, vector<vector<int>> &dp){
        if(target<0) return false;
        if(target==0) return true;
        if(idx>=nums.size()) return false;

        if(dp[idx][target]!=-1) return dp[idx][target];

        // adding to first subset
        if(helper(idx+1, nums, target-nums[idx],dp)) return true;

        // adding to second subset
        if(helper(idx+1,nums,target,dp)) return true;

        return dp[idx][target]=false;
    }

    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        int target=sum/2;

        vector<vector<int>> dp(nums.size(), vector<int>(target+1,-1));

        return helper(0,nums,target,dp);
    }
};