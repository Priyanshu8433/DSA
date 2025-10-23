class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        queue<int> q;
        int n=s.length();
        int cnt=0;

        while(true){

            // store all occurences of "01"
            for(int i=0; i<n-1; i++){
                string temp="";
                temp+=s[i];
                temp+=s[i+1];
                if(temp=="01"){
                    q.push(i);
                }
            }

            //replace all occurences of "01" with "10"
            if(!q.empty()){
                cnt++;
                while(!q.empty()){
                    int idx=q.front();
                    q.pop();

                    s[idx]='1';
                    s[idx+1]='0';
                }
            }
            else return cnt;
        }
        return cnt;
    }
};