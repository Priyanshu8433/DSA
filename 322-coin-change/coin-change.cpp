class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> prev(amount+1,1e9);

        for(int t = 0; t <= amount; t++){
            if(t % coins[0] == 0)
                prev[t] = t / coins[0];
        }

        for(int i=1; i<n; i++){
            for(int amn=0; amn<=amount; amn++){
                int take=INT_MAX;
                if(coins[i]<=amn) take=prev[amn-coins[i]]+1;

                int notTake=prev[amn];

                prev[amn]=min(take,notTake);
            }
        }
        
        return prev[amount]==1e9?-1:prev[amount];
    }
};