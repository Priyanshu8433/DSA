class Solution {
public:
    string removeSubstring(string s, int k) {
        stack<pair<char,int>> charSt;
        stack<int> cntSt;
        int i=0;
        int n=s.size();

        while(i<n){
            if(s[i]=='('){
                if(charSt.empty() || charSt.top().first==')'){
                    charSt.push({'(',1});
                }
                else{
                    charSt.push({'(',charSt.top().second+1});
                }
            }
            else{
                // s[i]==')'
                if(charSt.empty()){
                    charSt.push({')',1});
                }
                else if(charSt.top().first=='('){
                    cntSt.push(charSt.top().second);
                    charSt.push({')',1});
                }
                else{
                    charSt.push({')',charSt.top().second+1});
                }
                //check if k-balanced
                if(charSt.top().second==k && !cntSt.empty() && cntSt.top()>=k){
                    int temp=2*k;
                    while(!charSt.empty() && temp--){
                        charSt.pop();
                    }
                    cntSt.pop();
                }
            }
            i++;
        }
        string res="";
        while(!charSt.empty()){
            res+=charSt.top().first;
            charSt.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};