class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int cnt=0;
        for(char ch='a'; ch<='z'; ch++){
            int first=-1,last=-1;
            for(int i=0; i<s.length(); i++){
                if(s[i]==ch){
                    if(first==-1) first=i;
                    last=i;
                }
            }
            if(last>=first+1){
                int uniq=0;
                unordered_set<char> st;
                for(int i=first+1; i<last; i++) st.insert(s[i]);
                cnt+=st.size();
            }
        }
        return cnt;
    }
};