class NumMatrix {
    vector<vector<int>> mat;
public:
    NumMatrix(vector<vector<int>>& mat){
        int m=mat.size();
        int n=mat[0].size();
        // column summation
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                mat[i][j]+=mat[i-1][j];
            }
        }
        // row summation
        for(int j=1; j<n; j++){
            for(int i=0; i<m; i++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        this->mat=mat;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int lowerSum=0;
        lowerSum=mat[row2][col2]-(col1==0?0:mat[row2][col1-1]);
        int upperSum=0;
        if(row1==0){
            upperSum=0;
        }
        else{
            upperSum=mat[row1-1][col2]-(col1==0?0:mat[row1-1][col1-1]);
        }

        return lowerSum-upperSum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */