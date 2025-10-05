class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> res;

        queue<pair<int,int>> q;

        // bottom line
        vector<vector<int>> atVis(m,vector<int>(n,0));
        for(int j=0; j<n; j++){
            q.push({m-1,j});
            atVis[m-1][j]=1;
        }
        for(int i=0; i<m-1; i++){
            q.push({i,n-1});
            atVis[i][n-1]=1;
        }


        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};

            for(int i=0; i<4; i++){
                int nRow=row+delRow[i];
                int nCol=col+delCol[i];
                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && heights[row][col]<=heights[nRow][nCol] && !atVis[nRow][nCol]){
                    q.push({nRow,nCol});
                    atVis[nRow][nCol]=1;
                }
            }
        }

        vector<vector<int>> paVis(m,vector<int>(n,0));
        for(int j=0; j<n; j++){
            q.push({0,j});
            paVis[0][j]=1;
        }
        for(int i=1; i<m; i++){
            q.push({i,0});
            paVis[i][0]=1;
        }


        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(atVis[row][col]==1){
                res.push_back({row,col});
            }
            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};

            for(int i=0; i<4; i++){
                int nRow=row+delRow[i];
                int nCol=col+delCol[i];
                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && heights[row][col]<=heights[nRow][nCol] && !paVis[nRow][nCol]){
                    q.push({nRow,nCol});
                    paVis[nRow][nCol]=1;
                }
            }
        }

        return res;
    }
};