class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> stck;
        int n=s.length();
        for(int i=0; i<n; i++){
            if(stck.empty() || stck.top().first!=s[i]){
                stck.push({s[i],1});
            }
            else{
                stck.push({s[i],stck.top().second+1});
                if(stck.top().second==k){
                    for(int i=0; i<k; i++) stck.pop();
                }
            }
        }
        string res="";
        while(!stck.empty()){
            res+=stck.top().first;
            stck.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};