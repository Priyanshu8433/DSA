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
        vector<vector<int>> dp(n,vector<int>(amount+1,1e9));

        for(int i=0; i<n; i++) dp[i][0]=0;

        for(int t = 0; t <= amount; t++){
            if(t % coins[0] == 0)
                dp[0][t] = t / coins[0];
        }

        for(int i=1; i<n; i++){
            for(int amn=0; amn<=amount; amn++){
                int take=INT_MAX;
                if(coins[i]<=amn) take=dp[i][amn-coins[i]]+1;

                int notTake=dp[i-1][amn];

                dp[i][amn]=min(take,notTake);
            }
        }
        
        return dp[n-1][amount]==1e9?-1:dp[n-1][amount];
    }
};