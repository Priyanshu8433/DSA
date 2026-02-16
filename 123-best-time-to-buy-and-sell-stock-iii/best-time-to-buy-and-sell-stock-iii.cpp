class Solution {
public:
    int helper(int idx, vector<int> &prices, int trans,vector<vector<int>> &dp){
        if(trans<=0 || idx>=prices.size()) return 0;

        if(dp[idx][trans]!=-1) return dp[idx][trans];

        if(trans%2==0){
            // can buy only
            int buy=helper(idx+1,prices,trans-1,dp)-prices[idx];
            int notBuy=helper(idx+1,prices,trans,dp);

            return dp[idx][trans]=max(buy,notBuy);
        }
        else{
            // can sell only
            int sell=helper(idx+1,prices,trans-1,dp)+prices[idx];
            int notSell=helper(idx+1,prices,trans,dp);

            return dp[idx][trans]=max(sell,notSell);
        }

        return 0;
    }

    int maxProfit(vector<int>& prices) {
        // 4 3 2 1
        vector<vector<int>> dp(prices.size(), vector<int>(5,-1));
        return helper(0,prices,4,dp); 
    }
};