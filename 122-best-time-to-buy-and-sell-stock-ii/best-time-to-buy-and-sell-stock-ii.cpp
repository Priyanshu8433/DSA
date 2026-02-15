class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2,0));
        pair<int,int> prev={0,-1e9},curr;

        dp[0][1]=-1e9;

        for(int i=1; i<=prices.size(); i++){
            curr.second=max(prev.first-prices[i-1], prev.second);
            curr.first=max(prev.first,prev.second+prices[i-1]);

            prev=curr;
        }

        return prev.first; 
    }
};