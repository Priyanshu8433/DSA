class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> prev(2*k+1,0),curr(2*k+1,0);

        for(int t=1; t<=2*k; t+=2) prev[t]=-1e9;

        for(int i=1; i<=prices.size(); i++){
            for(int t=1; t<=2*k; t++){
                if(t%2==1){
                    curr[t]=max(prev[t-1]-prices[i-1],prev[t]);
                }
                else{
                    curr[t]=max(prev[t-1]+prices[i-1],prev[t]);
                }
            }
            prev=curr;
        }

        return prev[2*k];
    }
};