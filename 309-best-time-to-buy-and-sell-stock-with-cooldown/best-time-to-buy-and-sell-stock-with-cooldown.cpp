class Solution {
public:
    int helper(int idx, int canBuy, int cd, vector<int> &prices, vector<vector<vector<int>>> &dp){
        int n=prices.size();
        if(idx>=n) return 0;

        if(dp[idx][canBuy][cd]!=-1) return dp[idx][canBuy][cd];

        if(cd==0){
            if(canBuy){
                int buy=helper(idx+1,0,0,prices,dp)-prices[idx];
                int notBuy=helper(idx+1,1,0,prices,dp);
                return dp[idx][canBuy][cd]=max(buy,notBuy);
            }
            else{
                int sell=helper(idx+1,1,1,prices,dp)+prices[idx];
                int notSell=helper(idx+1,0,0,prices,dp);

                return dp[idx][canBuy][cd]=max(sell,notSell);
            }
        }
        else{
            return dp[idx][canBuy][cd]=helper(idx+1,1,0,prices,dp);
        }
        return 0;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return helper(0,1,0,prices,dp);
    }
};