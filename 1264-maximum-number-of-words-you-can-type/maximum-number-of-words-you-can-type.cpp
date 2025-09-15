class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int i=0;
        int n=text.length();
        int cnt=0;

        while(i<n){
            bool broken=false;
            while(i<n && text[i]!=' '){
                for(int j=0; j<brokenLetters.length(); j++){
                    if(text[i]==brokenLetters[j]) broken=true;
                }
                i++;
            }
            if(!broken) cnt++;
            i++;
        }
        return cnt;
    }
};