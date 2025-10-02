class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drank=numBottles;
        int emptyBottles=numBottles;
        numBottles=0;

        while(emptyBottles>=numExchange){
            numBottles++;
            emptyBottles-=numExchange;
            numExchange++;
        }

        drank+=numBottles;
        emptyBottles+=numBottles;
        
        if(emptyBottles>=numExchange) drank++;
        return drank;
    }
};