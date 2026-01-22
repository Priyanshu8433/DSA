class Solution {
public:
    int solve(int idx, int n, vector<int> &dp){
        if(idx>n) return 0;
        if(idx==n) return 1;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]=solve(idx+1,n,dp) + solve(idx+2,n,dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[n]=1;
        return solve(0,n,dp);
    }
};