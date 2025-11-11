class Solution {
public:
    pair<int,int> countStr(string str){
        int zeros=0,ones=0;
        for(char ch: str){
            if(ch=='1')ones++;
            else zeros++;
        }

        return {zeros,ones};
    }

    int solve(int idx, vector<string>& strs, int m, int n, vector<vector<vector<int>>> &dp){
        if(idx>=strs.size() || (m==0 && n==0)){
            return 0;
        }
        if(dp[idx][m][n]!=-1) return dp[idx][m][n];
        pair<int,int> cnt=countStr(strs[idx]); // first -> 0's | second -> 1's
        int take=INT_MIN,notTake=INT_MIN;
        //take
        if(m>=cnt.first && n>=cnt.second){
            take=solve(idx+1,strs,m-cnt.first,n-cnt.second,dp)+1;
        }
        //not take
        notTake=solve(idx+1,strs,m,n,dp);
        return dp[idx][m][n]=max(take,notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(0,strs,m,n,dp);
    }
};