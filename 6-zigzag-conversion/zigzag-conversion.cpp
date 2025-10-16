class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string> temp(numRows);
        int n=s.length();

        int cnt=0;
        int dir=1;
        int i=0;
        while(i<n){
            if(cnt>=0 && cnt<numRows){
                temp[cnt]+=s[i];
                cnt+=dir;
                i++;
            }

            if(cnt>=numRows){
                dir=-1;
                cnt+=dir;
                cnt+=dir;
            }
            else if(cnt<0){
                dir=1;
                cnt+=dir;
                cnt+=dir;
            }
        }
        string res="";
        for(auto str: temp){
            res+=str;
        }
        return res;
    }
};