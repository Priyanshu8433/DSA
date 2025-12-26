class Solution {
public:
    bool check(int r, int c, vector<string> &temp, int n){
        // Coloumn check
        for(int i=0; i<n; i++) if(temp[i][c]=='Q') return false;

        // Diagonal check
        int i=r-min(r,c);
        int j=c-min(r,c);
        for(; j<n && i<n && j>=0 && i>=0; i++,j++) if(temp[i][j]=='Q') return false;
        i=r+min(c,n-r-1);
        j=c-min(c,n-r-1);
        for(; j<n && i<n && j>=0 && i>=0; i--,j++) if(temp[i][j]=='Q') return false;
        return true;
    }

    void solve(int row, vector<vector<string>> &ans, vector<string> temp, int n){
        if(row>=n){
            ans.push_back(temp);
            return;
        }

        for(int col=0; col<n; col++){
            if(check(row,col,temp,n)){
                temp[row][col]='Q';
                solve(row+1,ans,temp,n);
                temp[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string str(n,'.');
        vector<string> temp(n,str);
        solve(0,ans,temp,n);
        return ans;
    }
};