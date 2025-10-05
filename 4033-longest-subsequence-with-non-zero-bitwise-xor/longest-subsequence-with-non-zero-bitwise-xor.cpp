class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int X=0;
        int cntZero=0;
        for(int x: nums){
            if(x==0) cntZero++;
            else X^=x;
        }
        int nonZero=nums.size()-cntZero;
        if(cntZero==nums.size()) return 0;
        if(X==0) return nonZero+cntZero-1;
        return nonZero+cntZero;
    }

};