class Solution {
public:
    bool solve(int row, int col, int idx, vector<vector<char>>& board, string &word, vector<vector<bool>> &vis){
        if(idx>=word.length() || (idx==word.length()-1 && board[row][col]==word.back())) return true;
        if(board[row][col]!=word[idx]) return false;
        vis[row][col]=true;

        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};

        for(int i=0; i<4; i++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];
            if(nRow>=0 && nRow<board.size() && nCol>=0 && nCol<board[0].size() && !vis[nRow][nCol]){
                vis[nRow][nCol]=true;
                if(solve(nRow,nCol,idx+1,board,word,vis)) return true;
                vis[nRow][nCol]=false;
            }
        }
        vis[row][col]=false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==word[0]){
                    //start pattern matching
                    if(solve(i,j,0,board,word,vis)) return true;
                }
            }
        }
        return false;
    }
};