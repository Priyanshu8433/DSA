class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> H(26,0);

        int i=0,j=0,maxLen=0;
        int n=s.length();
        while(j<n){
            H[s[j]-'A']++;

            

            while(j-i+1-(*max_element(H.begin(),H.end()))>k){
                H[s[i]-'A']--;
                i++;
            }

            maxLen=max(maxLen,j-i+1);
            j++;
        }

        return maxLen;
    }
};