class Solution {
public:
    int helper(int idx, int amount, vector<int>& coins, vector<vector<int>> &dp){
        int n=coins.size();
        if(amount==0) return 1;
        if(idx>=n) return 0;

        if(dp[idx][amount]!=-1) return dp[idx][amount];

        int take=0;
        if(coins[idx]<=amount) take=helper(idx,amount-coins[idx],coins,dp);

        int notTake=helper(idx+1,amount,coins,dp);

        return dp[idx][amount]=take+notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return helper(0,amount,coins,dp);
    }
};