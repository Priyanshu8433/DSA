class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2*k+1,0));

        for(int t=1; t<=2*k; t+=2) dp[0][t]=-1e9;

        for(int i=1; i<=prices.size(); i++){
            for(int t=1; t<=2*k; t++){
                if(t%2==1){
                    dp[i][t]=max(dp[i-1][t-1]-prices[i-1],dp[i-1][t]);
                }
                else{
                    dp[i][t]=max(dp[i-1][t-1]+prices[i-1],dp[i-1][t]);
                }
            }
        }

        return dp[prices.size()][2*k];
    }
};