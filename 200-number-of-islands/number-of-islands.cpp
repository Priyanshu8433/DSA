class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>> &vis){
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=true;

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};
            
            for(int i=0; i<4; i++){
                int nRow=row+delRow[i];
                int nCol=col+delCol[i];
                if(nRow>=0 && nRow<grid.size() && nCol>=0 && nCol<grid[0].size() && grid[nRow][nCol]=='1' && !vis[nRow][nCol]){
                    q.push({nRow,nCol});
                    vis[nRow][nCol]=true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;

        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    bfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};