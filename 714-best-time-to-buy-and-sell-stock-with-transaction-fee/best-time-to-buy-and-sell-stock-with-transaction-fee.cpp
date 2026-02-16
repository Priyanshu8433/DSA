class Solution {
public:
    int helper(int idx, int canBuy, vector<int> &prices, int fee, vector<vector<int>> &dp){
        int n=prices.size();
        if(idx>=n) return 0;

        if(dp[idx][canBuy]!=-1) return dp[idx][canBuy];

        if(canBuy){
            int buy=helper(idx+1,0,prices,fee,dp)-prices[idx]-fee;
            int notBuy=helper(idx+1,1,prices,fee,dp);

            return dp[idx][canBuy]=max(buy,notBuy);
        }
        else{
            int sell=helper(idx+1,1,prices,fee,dp)+prices[idx];
            int notSell=helper(idx+1,0,prices,fee,dp);

            return dp[idx][canBuy]=max(sell,notSell);
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return helper(0,1,prices,fee,dp);
    }
};