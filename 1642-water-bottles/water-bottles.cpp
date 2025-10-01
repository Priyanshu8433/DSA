class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drank=numBottles;
        while(numBottles>=numExchange){
            int canDrink=numBottles/numExchange;
            drank+=canDrink;
            numBottles%=numExchange;
            numBottles+=canDrink;
        }
        return drank;
    }
};