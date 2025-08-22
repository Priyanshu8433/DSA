class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int iR=INT_MAX,iC=INT_MAX;
        int lR=INT_MIN,lC=INT_MIN;
        for(int r=0; r<m; r++){
            for(int c=0; c<n; c++){
                if(grid[r][c]==1){
                    iR=min(iR,r);
                    iC=min(iC,c);
                    lR=max(lR,r);
                    lC=max(lC,c);
                }
            }
        }

        int area=(lR-iR+1)*(lC-iC+1);
        return area;
    }
};