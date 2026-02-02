class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},0});
        reverse(board.begin(),board.end());
        int lastPos=(n*n);
        int lastRow=(lastPos-1)/n;
        int lastCol=(lastPos-1)%n;
        if(lastRow%2==1){
            lastCol=n-lastCol-1;
        }
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int moves=q.front().second;
            q.pop();

            // traverse all adjacent node (Simulate a die throw)
            int dir=(row%2==0?1:-1); // direction of curr row

            for(int num=1; num<=6; num++){ // possible dice numbers
                int currRow=row;
                int currCol=col;
                int nRow=row;
                int nCol=col+dir;
                if(nCol<0 || nCol>=n){
                    nRow++;
                    if(dir==1){
                        // dir==1 --> went above n
                        nCol=n-1;
                    }
                    else{
                        // dir==-1 --> went below 0
                        nCol=0;
                    }
                    dir*=(-1); // reverse the direction
                }

                // check constraints
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<n){
                    // check if it's a ladder or snake
                    if(nRow==lastRow && nCol==lastCol) return moves+1;
                    if(board[nRow][nCol]!=-1){
                        int nextPos=board[nRow][nCol];

                        // calculate adj row and col
                        int adjRow=(nextPos-1)/n;
                        int adjCol=(nextPos-1)%n;
                        if(adjRow%2==1){
                            adjCol=n-adjCol-1;
                        }
                        if(!vis[adjRow][adjCol]){
                            q.push({{adjRow,adjCol},moves+1});
                            if(adjRow==lastRow && adjCol==lastCol) return moves+1;
                            vis[adjRow][adjCol]=1;
                            cout<<adjRow<<" "<<adjCol<<":"<<moves+1<<"--"<<nextPos<<endl;
                        }
                    }
                    else{
                        if(!vis[nRow][nCol]){
                            q.push({{nRow,nCol},moves+1});
                            vis[nRow][nCol]=1;
                            cout<<nRow<<" "<<nCol<<":"<<moves+1<<endl;
                        }
                    }
                }
                row=nRow;
                col=nCol;
            }
        }

        return -1;
    }
};