class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));

        dp[0][1]=-1e9;

        for(int i=1; i<=n; i++){
            dp[i][1]=max(dp[i-1][0]-prices[i-1]-fee,dp[i-1][1]);
            dp[i][0]=max(dp[i-1][1]+prices[i-1], dp[i-1][0]);
        }

        return dp[n][0];
    }
};