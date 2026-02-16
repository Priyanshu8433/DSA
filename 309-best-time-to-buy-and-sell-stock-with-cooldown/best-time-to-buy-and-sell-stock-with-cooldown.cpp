class Solution {
public:
    int helper(int idx, int canBuy,vector<int> &prices, vector<vector<int>> &dp){
        int n=prices.size();
        if(idx>=n) return 0;

        if(dp[idx][canBuy]!=-1) return dp[idx][canBuy];
        if(canBuy){
            int buy=helper(idx+1,0,prices,dp)-prices[idx];
            int notBuy=helper(idx+1,1,prices,dp);
            return dp[idx][canBuy]=max(buy,notBuy);
        }
        else{
            int sell=helper(idx+2,1,prices,dp)+prices[idx];
            int notSell=helper(idx+1,0,prices,dp);

            return dp[idx][canBuy]=max(sell,notSell);
        }
        return 0;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return helper(0,1,prices,dp);
    }
};