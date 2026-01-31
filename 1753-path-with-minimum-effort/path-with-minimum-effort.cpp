class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> vis(n,vector<int>(m,INT_MAX));
        auto cmp=[](pair<int,pair<int,int>> &a, pair<int,pair<int,int>>& b){
            return a.first>b.first;
        };
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, decltype(cmp) > pq(cmp);
        vis[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int currHeight=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};
            for(int i=0; i<4; i++){
                int nRow=row+delRow[i];
                int nCol=col+delCol[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m){
                    int newHeight=max(currHeight,abs(heights[nRow][nCol]-heights[row][col]));
                    if(newHeight<vis[nRow][nCol]){
                        vis[nRow][nCol]=newHeight;
                        pq.push({newHeight,{nRow,nCol}});
                    }
                }
            }
        }

        return vis[n-1][m-1];
    }
};