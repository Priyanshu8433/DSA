class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vis(m,vector<int>(n,-1)); // 1->guard 2->wall -1->unvisited 0->visited
        for(auto vec: guards){
            vis[vec[0]][vec[1]]=1; // guard
        }
        for(auto vec: walls){
            vis[vec[0]][vec[1]]=2; // walls
        }

        for(auto vec: guards){
            int row=vec[0];
            int col=vec[1];
            
            // top
            for(int i=row-1; i>=0; i--){
                if(vis[i][col]==1 || vis[i][col]==2) break;
                vis[i][col]=0;
            }

            // right
            for(int i=col+1; i<n; i++){
                if(vis[row][i]==1 || vis[row][i]==2) break;
                vis[row][i]=0;
            }

            // left
            for(int i=col-1; i>=0; i--){
                if(vis[row][i]==1 || vis[row][i]==2) break;
                vis[row][i]=0;
            }

            // down
            for(int i=row+1; i<m; i++){
                if(vis[i][col]==1 || vis[i][col]==2) break;
                vis[i][col]=0;
            }
        }
        int cnt=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j]==-1) cnt++;
            }
        }
        return cnt;
    }
};