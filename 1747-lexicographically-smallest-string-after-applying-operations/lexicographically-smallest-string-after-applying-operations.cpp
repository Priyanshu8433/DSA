class Solution {
public:

    void rotate(string &s, int b){
        reverse(s.begin(),s.end());
        reverse(s.begin(),s.begin()+b);
        reverse(s.begin()+b,s.end());
    }

    void add(string &s, int a){
        int n=s.length();
        for(int i=1; i<n; i+=2){
            s[i]=((s[i]-'0'+a)%10)+'0';
        }
    }

    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        q.push(s);
        string minStr=s;
        unordered_set<string> st;
        st.insert(s);

        while(!q.empty()){
            string curr=q.front();
            q.pop();
            
            if(curr<minStr) minStr=curr;

            //add
            string temp=curr;
            add(temp,a);

            if(!st.count(temp)){
                st.insert(temp);
                q.push(temp);
            }

            //rotate
            rotate(curr,b);
            if(!st.count(curr)){
                st.insert(curr);
                q.push(curr);
            }
        }

        return minStr;
    }
};