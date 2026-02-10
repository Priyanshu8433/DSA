class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;

        for(char ch: num){
            while(k>0 && !s.empty() && s.top()>ch){
                s.pop();
                k--;
            }
            s.push(ch);
        }

        while(!s.empty() && k){
            s.pop();
            k--;
        }

        string res="";

        while(!s.empty()){
            res+=s.top();
            s.pop();
        }
        while(res.size() && res.back()=='0') res.pop_back();

        reverse(res.begin(),res.end());

        return res.size()?res:"0";
    }
};