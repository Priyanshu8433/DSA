class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int prevMin=INT_MAX;
        for(int price: prices){
            prevMin=min(prevMin,price);
            maxi=max(maxi,price-prevMin);
        }
        return maxi;
    }
};