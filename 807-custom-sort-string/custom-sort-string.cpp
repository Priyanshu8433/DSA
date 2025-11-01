class Solution {
public:
    string customSortString(string order, string s) {
        int n=order.length();
        int m=s.length();
        int idx=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(s[j]==order[i]){
                    swap(s[j],s[idx]);
                    idx++;
                }
            }
        }
        return s;
    }
};