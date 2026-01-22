class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp){
        int m=grid.size();
        int n=grid[0].size();

        if(dp[i][j]!=-1) return dp[i][j];

        if(i==m-1 && j==n-1) return grid[i][j];
        int down=INT_MAX,right=INT_MAX;
        if(i+1<m) down=solve(i+1,j,grid,dp);
        if(j+1<n) right=solve(i,j+1,grid,dp);

        return dp[i][j]=min(down,right)+grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,grid,dp);
    }
};