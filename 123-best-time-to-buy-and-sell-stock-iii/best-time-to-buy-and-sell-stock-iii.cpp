class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> prev(5,0),curr(5);

        prev[1]=-1e9;
        prev[3]=-1e9;

        for(int idx=1; idx<=prices.size(); idx++){
            for(int trans=1; trans<5; trans++){
                if(trans%2==1){
                    curr[trans]=max(prev[trans-1]-prices[idx-1], prev[trans]);
                }
                else{
                    curr[trans]=max(prev[trans-1]+prices[idx-1],prev[trans]);
                }
            }
            prev=curr;
        }


        return prev[4];
    }
};