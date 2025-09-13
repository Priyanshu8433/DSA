class Solution {
public:
    int maxFreqSum(string s) {
        int n=s.length();
        int hV=0;
        int hC=0;
        
        int h[26]={0};
        
        for(int i=0; i<n; i++){
            h[s[i]-'a']++;
        }
        
        for(int i=0; i<26; i++){
            if(i==0||i==4||i==8||i==14||i==20){
                //is vowel
                hV=max(hV,h[i]);
            }
            else{
                //is consonant
                hC=max(hC,h[i]);
            }
        }
        
        return hC+hV;
        
    }
};