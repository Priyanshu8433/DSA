class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<long long>> dp(n,vector<long long>(amount+1,0));
        for(int i=0; i<n; i++) dp[i][0]=1;     
        for(int t=0; t<=amount; t++){
            if(t%coins[0]==0) dp[0][t]=1;
        }

        for(int i=1; i<n; i++){
            for(int t=0; t<=amount; t++){
                int take=0;
                if(coins[i]<=t) take=dp[i][t-coins[i]];
                int notTake=dp[i-1][t];

                dp[i][t]=0ll+take+notTake;
            }
        }

        return dp[n-1][amount];
    }
};