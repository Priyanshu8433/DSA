class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m=bank.size();
        int n=bank[0].size();
        int prev=0;
        int combination=0;
        for(int i=m-1; i>=0; i--){
            int curr=0;
            for(int j=0; j<n; j++){
                if(bank[i][j]=='1') curr++;
            }
            combination+=(curr*prev);
            if(curr)
                prev=curr;
        }
        return combination;
    }
};