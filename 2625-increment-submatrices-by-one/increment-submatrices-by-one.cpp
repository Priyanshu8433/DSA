class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n,vector<int>(n,0));

        for(auto query: queries){
            int x1=query[0],y1=query[1],x2=query[2],y2=query[3];
            for(int i=x1; i<=x2; i++){
                mat[i][y1]++;
                if(y2+1<n) mat[i][y2+1]--;
            }
        }

        for(int i=0; i<n; i++){
            int currSum=0;
            for(int j=0; j<n; j++){
                currSum+=mat[i][j];
                mat[i][j]=currSum;
            }
        }

        return mat;
    }
};