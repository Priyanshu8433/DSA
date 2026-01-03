class Solution {
public:

    int MOD=1e9+7;

    void generate(int idx, char prev, int m, vector<string> &arr, string temp){
        if(idx>=m){
            arr.push_back(temp);
            return;
        }

        string s="RGB";
        for(char ch: s){
            if(ch!=prev){
                temp+=ch;
                generate(idx+1,ch,m,arr,temp);
                temp.pop_back();
            }
        }
    }

    bool check(string &s1, string &s2, int m){
        for(int i=0; i<m; i++) if(s1[i]==s2[i]) return false;
        return true;
    }

    int solve(int row, string prev, int m, int n, vector<string> &rows, vector<unordered_map<string,int>> &dp){
        if(row>=n) return 1;

        if(dp[row].count(prev)) return dp[row][prev];

        int cnt=0;
        for(int i=0; i<rows.size(); i++){
            if(check(prev,rows[i],m)) cnt=cnt%MOD+solve(row+1,rows[i],m,n,rows,dp)%MOD;
        }      

        return dp[row][prev]=cnt%MOD;
    }

    int colorTheGrid(int m, int n) {
        vector<unordered_map<string,int>> dp(n);
        vector<string> rows;
        generate(0,'#',m,rows,"");
        return solve(0,"",m,n,rows,dp);
    }
};