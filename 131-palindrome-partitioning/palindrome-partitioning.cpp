class Solution {
public:
    bool isPalindrome(string &s){
        int n=s.length();
        for(int i=0; i<n/2; i++){
            if(s[i]!=s[n-i-1]) return false;
        }
        return true;
    }

    void solve(int idx, string &s, vector<vector<string>> &ans, vector<string> temp){
        int n=s.length();
        if(idx>=n){
            ans.push_back(temp);
            return;
        }

        for(int i=1; i+idx<=n; i++){
            string left=s.substr(idx,i);
            if(isPalindrome(left)){
                temp.push_back(left);
                solve(idx+i,s,ans,temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        solve(0,s,ans,{});
        return ans;
    }
};