class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>> sq_length(m,vector<int>(n,-1));
        sq_length[m-1][n-1]=matrix[m-1][n-1]-'0';
        int dr=m-1,dc=n-1;

        while(dr>=0 && dc>=0){
            // bottom to top
            for(int row=dr; row>=0; row--){
                if(matrix[row][dc]=='1'){
                    int down=(row+1<m? sq_length[row+1][dc]:0);
                    int right=(dc+1<n?sq_length[row][dc+1]:0);
                    int diag=((row+1<m && dc+1<n)?sq_length[row+1][dc+1]:0);
                    sq_length[row][dc]=min(down,min(right,diag))+1;
                }
                else sq_length[row][dc]=0;
            }

            // right to left
            for(int col=dc-1; col>=0; col--){
                if(matrix[dr][col]=='1'){
                    int down=(dr+1<m?sq_length[dr+1][col]:0);
                    int right=(col+1<n?sq_length[dr][col+1]:0);
                    int diag=((col+1<n && dr+1<m)?sq_length[dr+1][col+1]:0);
                    sq_length[dr][col]=min(down,min(right,diag))+1;
                }
                else sq_length[dr][col]=0;
            }

            dr--;
            dc--;
        }
        int x=-1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
            x=max(x,sq_length[i][j]);
        }
        return x*x;
    }
};