class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int nCnt=0;
        long long nSum=0,pSum=0;
        int mini=INT_MAX;
        bool flag=false;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int x=matrix[i][j];
                if(x==0) flag=true;
                else if(x<0){
                    x*=-1;
                    nSum+=x;
                    nCnt++;
                    mini=min(mini,x);
                }
                else{
                    mini=min(mini,x);
                    pSum+=x;
                }
            }
        }
        if(flag || nCnt%2==0) return nSum+pSum;
        return nSum+pSum-2*mini;
    }
};