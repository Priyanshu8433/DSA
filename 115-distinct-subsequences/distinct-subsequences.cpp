class Solution {
public:
    int MOD=INT_MAX;

    int helper(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        int n=s.size(),m=t.size();
        if(j>=m) return 1;
        if(i>=n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]){
            int take=helper(i+1,j+1,s,t,dp);
            int notTake=helper(i+1,j,s,t,dp);

            return dp[i][j]=take+notTake;
        }
        else{
            return dp[i][j]=helper(i+1,j,s,t,dp);
        }
    }

    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();

        vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));

        for(int i=0; i<=n; i++) dp[i][0]=1;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=(0ll+dp[i-1][j-1]%MOD+dp[i-1][j]%MOD)%MOD;
                }
                else dp[i][j]=dp[i-1][j]%MOD;
            }
        }


        return dp[n][m];
    }
};