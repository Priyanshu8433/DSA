class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 4 3 2 1
        vector<vector<int>> dp(prices.size()+1, vector<int>(5,0));

        dp[0][1]=-1e9;
        dp[0][3]=-1e9;

        for(int idx=1; idx<=prices.size(); idx++){
            for(int trans=1; trans<5; trans++){
                if(trans%2==1){
                    dp[idx][trans]=max(dp[idx-1][trans-1]-prices[idx-1], dp[idx-1][trans]);
                }
                else{
                    dp[idx][trans]=max(dp[idx-1][trans-1]+prices[idx-1],dp[idx-1][trans]);
                }
            }
        }


        return dp[prices.size()][4];
    }
};