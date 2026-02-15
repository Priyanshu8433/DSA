class Solution {
public:
    int helper(int idx, vector<int> &prices, bool flag, vector<vector<int>> &dp){
        int n=prices.size();
        if(idx>=n) return 0;

        if(dp[idx][flag]!=-1) return dp[idx][flag];

        // flag==true --> can buy share


        if(flag){
            int buy=helper(idx+1,prices,false,dp)-prices[idx];
            int notBuy=helper(idx+1,prices,true,dp);

            return dp[idx][flag]=max(buy,notBuy);
        }
        else{
            int sell=helper(idx+1,prices,true,dp)+prices[idx];
            int notSell=helper(idx+1,prices,false,dp);

            return dp[idx][flag]=max(sell,notSell);
        }

        return 0;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2,0));
        dp[0][1]=-1e9;

        for(int i=1; i<=prices.size(); i++){
            dp[i][1]=max(dp[i-1][0]-prices[i-1], dp[i-1][1]);
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i-1]);
        }

        return dp[prices.size()][0]; 
    }
};