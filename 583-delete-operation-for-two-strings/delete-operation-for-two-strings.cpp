class Solution {
public:
    int lcs(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        int n=word1.size(),m=word2.size();
        if(i>=n || j>=m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i]==word2[j]){
            return dp[i][j]=lcs(i+1,j+1,word1,word2,dp)+1;
        }
        else{
            int left=lcs(i+1,j,word1,word2,dp);
            int right=lcs(i,j+1,word1,word2,dp);

            return dp[i][j]=max(left,right);
        }
    }

    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        int len=lcs(0,0,word1,word2,dp);

        return (n-len)+(m-len);
    }
};