class Solution {
public: 
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> prev(text2.size()+1,0),curr(text2.size()+1,0);

        for(int i=1; i<=text1.size(); i++){
            for(int j=1; j<=text2.size(); j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j]=prev[j-1]+1;
                }
                else{
                    int left=prev[j];
                    int right=curr[j-1];
                    curr[j]=max(left,right);
                }
            }
            prev=curr;
        }

        return prev[text2.size()];
    }
};