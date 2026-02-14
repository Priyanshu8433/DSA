class Solution {
public:
    int helper(int i, int j, string &s, vector<vector<int>> &dp){
        int n=s.length();
        if(i<0 || j>=n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]){
            return dp[i][j]=helper(i-1,j+1,s,dp)+(i==j?1:2);
        }
        else{
            int left=helper(i-1,j,s,dp);
            int right=helper(i,j+1,s,dp);

            return dp[i][j]=max(left,right);
        }
    }

    int longestPalindromeSubseq(string s) {
        int n=s.length();
        int maxi=0;

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        for(int i=0; i<n; i++){
            maxi=max(maxi,helper(i,i,s,dp));
            if(i<n-1) maxi=max(maxi,helper(i,i+1,s,dp));
        }
        return maxi;
    }
};