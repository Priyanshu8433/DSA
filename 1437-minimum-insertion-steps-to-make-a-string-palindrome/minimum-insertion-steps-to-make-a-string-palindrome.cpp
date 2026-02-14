class Solution {
public:
    int helper(int i, int j, string &s, vector<vector<int>> &dp){
        if(i>=j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]){
            return dp[i][j]=helper(i+1,j-1,s,dp);
        }
        else{
            int left=helper(i+1,j,s,dp)+1;
            int right=helper(i,j-1,s,dp)+1;

            return dp[i][j]=min(left,right);
        }
    }

    int minInsertions(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return helper(0,n-1,s,dp);
    }
};