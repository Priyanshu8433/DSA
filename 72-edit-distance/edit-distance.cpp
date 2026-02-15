class Solution {
public:
    int helper(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(j<0){
            return i+1;
        }
        if(i<0) return j+1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]){
            return dp[i][j]=helper(i-1,j-1,s1,s2,dp);
        }
        else{
            // insert 
            int insertChar=helper(i,j-1,s1,s2,dp)+1;
            // delete
            int delChar=helper(i-1,j,s1,s2,dp)+1;
            // replace
            int replaceChar=helper(i-1,j-1,s1,s2,dp)+1;

            return dp[i][j]=min(min(insertChar,delChar),replaceChar);
        }
    }

    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,word1,word2,dp);
    }
};