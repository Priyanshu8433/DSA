class Solution {
public:
    vector<vector<int>> rows={{1,2,1},{1,2,3},{1,3,1},{1,3,2},
                              {2,1,2},{2,1,3},{2,3,1},{2,3,2},
                              {3,1,2},{3,1,3},{3,2,1},{3,2,3}};

    bool check(vector<int> &v1, vector<int> &v2){
        for(int i=0; i<3; i++){
            if(v1[i]==v2[i]) return false;
        }
        return true;
    }
    int MOD=1e9+7;
    int solve(int row, int prevRow, int n,vector<vector<vector<vector<int>>>> &dp){
        if(row>=n){
            return 1;
        }

        if(row!=0 && dp[row][rows[prevRow][0]][rows[prevRow][1]][rows[prevRow][2]]!=-1) return dp[row][rows[prevRow][0]][rows[prevRow][1]][rows[prevRow][2]];

        int cnt=0;
        for(int i=0; i<12; i++){
            if(row==0 || check(rows[i],rows[prevRow])){
                cnt=cnt%MOD+solve(row+1,i,n,dp)%MOD;
            }
        }

        return dp[row][rows[prevRow][0]][rows[prevRow][1]][rows[prevRow][2]]=cnt%MOD;
    }
    int numOfWays(int n) {
        vector<vector<vector<vector<int>>>> dp(n+1,vector<vector<vector<int>>>(4,vector<vector<int>>(4,vector<int>(4,-1))));
        return solve(0,0,n, dp)%MOD;
    }
};