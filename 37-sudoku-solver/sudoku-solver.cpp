class Solution {
public:

    int gridIdx(int i, int j){
        if(i<=2){
            if(j<=2){
                return 0;
            }
            else if(j<=5){
                return 1;
            }
            else{
                return 2;
            }
        }
        else if(i<=5){
            if(j<=2){
                return 3;
            }
            else if(j<=5){
                return 4;
            }
            else{
                return 5;
            }
        }
        else{
            if(j<=2){
                return 6;
            }
            else if(j<=5){
                return 7;
            }
            else{
                return 8;
            }
        }
    }
    
    bool check(int i, int j, int val, vector<vector<bool>> &rowCheck, vector<vector<bool>> &colCheck, vector<vector<bool>> &gridCheck){
        // row check
        if(rowCheck[i][val]) return false;
        //column check
        if(colCheck[j][val]) return false;
        //grid check
        if(gridCheck[gridIdx(i,j)][val]) return false;
        return true;
    }

    bool solve(int idx, vector<vector<char>>& board, vector<pair<int,int>> &empty,  vector<vector<bool>> &rowCheck, vector<vector<bool>> &colCheck, vector<vector<bool>> &gridCheck){
        if(idx>=empty.size()) return true;

        int row=empty[idx].first;
        int col=empty[idx].second;

        for(int i=1; i<=9; i++){
            if(check(row,col,i,rowCheck,colCheck,gridCheck)){
                board[row][col]=i+'0';
                rowCheck[row][i]=true;
                colCheck[col][i]=true;
                gridCheck[gridIdx(row,col)][i]=true;
                if(solve(idx+1,board,empty,rowCheck,colCheck,gridCheck)) return true;
                rowCheck[row][i]=false;
                colCheck[col][i]=false;
                gridCheck[gridIdx(row,col)][i]=false;
                board[row][col]='.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int,int>> empty;

        vector<vector<bool>> rowCheck(9,vector<bool>(10,false));
        vector<vector<bool>> colCheck(9,vector<bool>(10,false));
        vector<vector<bool>> gridCheck(9,vector<bool>(10,false));

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.') empty.push_back({i,j});
                else{
                    int val=board[i][j]-'0';
                    rowCheck[i][val]=true;
                    colCheck[j][val]=true;
                    gridCheck[gridIdx(i,j)][val]=true;
                }
            }
        }
        solve(0,board,empty,rowCheck,colCheck,gridCheck);
    }
};