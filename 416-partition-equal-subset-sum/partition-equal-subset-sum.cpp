class Solution {
public:
    bool solve(int idx, vector<int> &nums, int target, vector<vector<int>> &dp){
        int n=nums.size();
        if(idx>=n){
            if(target==0) return true;
            return false;
        }
        if(target<0) return false;

        if(dp[idx][target]!=-1) return false;

        if(solve(idx+1,nums,target-nums[idx],dp)) return true;
        if(solve(idx+1,nums,target,dp)) return true;
        return dp[idx][target]=false;
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        int target=sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(0,nums,target,dp);
    }
};