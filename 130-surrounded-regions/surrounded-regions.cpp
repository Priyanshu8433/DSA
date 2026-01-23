class Solution {
public:
    void bfs(int x, int y, vector<vector<char>>& board, vector<vector<int>> &vis, bool flag){
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>> q;
        q.push({x,y});
        vis[x][y]=1;
        if(flag) board[x][y]='X';

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};

            for(int i=0; i<4; i++){
                int nRow=row+delRow[i];
                int nCol=col+delCol[i];
                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && !vis[nRow][nCol] && board[nRow][nCol]=='O'){
                    vis[nRow][nCol]=1;
                    if(flag) board[nRow][nCol]='X';
                    q.push({nRow,nCol});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int j=0; j<n; j++){
            if(board[0][j]=='O') bfs(0,j,board,vis,false);
            if(board[m-1][j]=='O') bfs(m-1,j,board,vis,false);
        }

        for(int i=1; i<m-1; i++){
            if(board[i][0]=='O') bfs(i,0,board,vis,false);
            if(board[i][n-1]=='O') bfs(i,n-1,board,vis,false);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O' && !vis[i][j]) bfs(i,j,board,vis,true);
            }
        }
    }
};