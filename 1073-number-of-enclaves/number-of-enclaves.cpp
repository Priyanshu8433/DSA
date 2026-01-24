class Solution {
public:
    int bfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis){
        int cnt=0;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        cnt++;

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};

            for(int i=0; i<4; i++){
                int nRow=row+delRow[i];
                int nCol=col+delCol[i];

                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && !vis[nRow][nCol] && grid[nRow][nCol]==1){
                    q.push({nRow,nCol});
                    vis[nRow][nCol]=1;
                    cnt++;
                }
            }
        }

        return cnt;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i=0; i<m; i++){
            if(grid[i][0]==1 && !vis[i][0]) bfs(i,0,grid,vis);
            if(grid[i][n-1]==1 && !vis[i][n-1]) bfs(i,n-1,grid,vis);
        }

        for(int j=1; j<n-1; j++){
            if(grid[0][j]==1 && !vis[0][j]) bfs(0,j,grid,vis);
            if(grid[m-1][j]==1 && !vis[m-1][j]) bfs(m-1,j,grid,vis);
        }


        int cnt=0;
        for(int i=1; i<m-1; i++){
            for(int j=1; j<n-1; j++){
                if(!vis[i][j] && grid[i][j]) cnt+=bfs(i,j,grid,vis);
            }
        }
        return cnt;
    }
};