class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid,vector<vector<int>> &dp){
        int m=grid.size();
        int n=grid[0].size();
        if(i==m-1 && j==n-1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int down=0,right=0;

        // move down
        if(i+1<m && grid[i+1][j]==0) down=solve(i+1,j,grid,dp);

        // move right
        if(j+1<n && grid[i][j+1]==0) right=solve(i,j+1,grid,dp);

        return dp[i][j]=down+right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1) return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,grid,dp);
    }
};