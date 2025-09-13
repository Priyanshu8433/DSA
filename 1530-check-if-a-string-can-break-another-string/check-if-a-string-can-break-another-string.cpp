class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());

        bool flag=true;
        int n=s1.size();

        //s1 cuts s2
        for(int i=0; i<n; i++){
            if(s1[i]<s2[i]) flag=false;
        }

        if(flag) return true;

        flag=true;
        
        //s2 cuts s1
        for(int i=0; i<n; i++){
            if(s2[i]<s1[i]) flag=false;
        }

        if(flag) return true;
        return false;
    }
};