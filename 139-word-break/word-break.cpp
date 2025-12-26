class Solution {
public:
    bool solve(int idx, string &s, unordered_set<string> &st, vector<int> &dp, bool flag){
        int n=s.length();
        if(idx>=n) return true;

        if(flag && dp[idx]!=-1) return dp[idx];

        for(int i=1; i+idx<=n; i++){
            string str=s.substr(idx,i);
            if(st.count(str)){
                if(solve(idx+i,s,st,dp,flag)) return true;
            }
        }
        if(flag) dp[idx]=false;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // unordered_set<string> st(wordDict.begin(),wordDict.end());
        unordered_set<string> st;
        sort(wordDict.begin(),wordDict.end(), [](string &a, string &b){
            return a.length()<b.length();
        });
        vector<int> dp(s.length()+1,-1);
        for(string x: wordDict){
            if(!solve(0,x,st,dp,false)) st.insert(x);
        }

        return solve(0,s,st,dp,true);
    }
};