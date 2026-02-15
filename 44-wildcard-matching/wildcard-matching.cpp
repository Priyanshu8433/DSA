class Solution {
public:
    bool helper(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        int n=s.length(),m=p.length();
        if (j == m)
            return i == n;

        if (i == n) {
            for (int k = j; k < m; k++)
                if (p[k] != '*')
                    return false;
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=helper(i+1,j+1,s,p,dp);
        }
        else if(p[j]=='*'){
            return dp[i][j]=helper(i+1,j,s,p,dp) || helper(i,j+1,s,p,dp);
        }
        return dp[i][j]=false;
    }

    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return helper(0,0,s,p,dp);
    }
};