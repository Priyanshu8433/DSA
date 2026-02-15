class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin=INT_MAX;
        int profit=0;

        for(int price: prices){
            profit=max(max(0,price-currMin),profit);
            currMin=min(currMin,price);
        }

        return profit;
    }
};