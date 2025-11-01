class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int nextIdle=customers[0][0];
        int n=customers.size();
        double waitTime=0;

        for(int i=0; i<n; i++){
            nextIdle=max(nextIdle,customers[i][0])+customers[i][1];
            waitTime=(double)waitTime+((double)(nextIdle-customers[i][0])/n);
        }
        return waitTime;
    }
};