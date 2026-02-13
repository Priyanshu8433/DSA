class Solution {
public:
    int helper(int idx, vector<int>& coins, int amount, vector<vector<int>> &dp){
        int n=coins.size();
        if(idx>=n){
            if(amount==0) return 0;
            return 1e9;
        }

        if(dp[idx][amount]!=-1) return dp[idx][amount];

        // take this coin
        int take=INT_MAX;
        if(coins[idx]<=amount) take=helper(idx,coins,amount-coins[idx],dp)+1;

        // dont take this coin
        int notTake=helper(idx+1,coins,amount,dp);

        return dp[idx][amount]=min(take,notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=helper(0,coins,amount,dp);
        return ans==1e9?-1:ans;
    }
};