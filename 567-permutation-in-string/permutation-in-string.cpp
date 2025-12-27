class Solution {
public:
    bool check(int c1[], int c2[]){
        for(int i=0; i<26; i++){
            if(c1[i]!=c2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int count1[26]={0};
        int count2[26]={0};
        for(char ch: s1) count1[ch-'a']++;

        int n=s2.length();
        int left=0,right=0;
        while(right<n){
            count2[s2[right]-'a']++;
            if(right-left+1>s1.length()){
                count2[s2[left]-'a']--;
                left++;
            }
            if(right-left+1==s1.length()){
                if(check(count1,count2)) return true;
            }
            right++;
        }
        return false;
    }
};