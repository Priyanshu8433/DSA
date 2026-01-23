class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2) q.push({{i,j},0});
            }
        }
        int maxTime=0;

        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int time=q.front().second;
            q.pop();
            maxTime=max(maxTime,time);

            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};
            for(int i=0; i<4; i++){
                int nRow=x+delRow[i];
                int nCol=y+delCol[i];
                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && grid[nRow][nCol]==1){
                    grid[nRow][nCol]=2;
                    q.push({{nRow,nCol},time+1});
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) return -1;
            }
        }

        return maxTime;
    }
};