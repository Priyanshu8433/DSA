class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();

        queue<pair<int,int>> q;
        int ogCol=image[sr][sc];
        if(ogCol==color) return image;

        q.push({sr,sc});
        image[sr][sc]=color;

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};

            for(int i=0; i<4; i++){
                int nRow=row+delRow[i];
                int nCol=col+delCol[i];
                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && image[nRow][nCol]==ogCol){
                    image[nRow][nCol]=color;
                    q.push({nRow,nCol});
                }
            }
        }

        return image;
    }
};