class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<=i; j++){
                if(i==0) dp[0][0]=triangle[0][0];
                else{
                    int up=INT_MAX,lUp=INT_MAX;
                    if(j!=i) up=dp[i-1][j];
                    if(j!=0) lUp=dp[i-1][j-1];
                    dp[i][j]=min(up,lUp)+triangle[i][j];
                }
            }
        }

        return *min_element(dp[m-1].begin(),dp[m-1].end());
    }
};