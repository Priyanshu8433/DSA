class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) dp[i][j]=1;
                else{
                    int top=0,left=0;
                    if(i-1>=0) top=dp[i-1][j];
                    if(j-1>=0) left=dp[i][j-1];
                    dp[i][j]=top+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};