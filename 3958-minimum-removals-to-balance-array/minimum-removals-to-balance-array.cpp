class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left=0,right=0;
        int n=nums.size();
        int maxLen=1;
        while(right<n){
            double quotient=(double)nums[right]/nums[left];
            if(quotient<=k){
                maxLen=max(maxLen,right-left+1);
                right++;
            }
            else left++;
        }
        return n-maxLen;
    }
};