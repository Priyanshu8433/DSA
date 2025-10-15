class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int i=1,j=k+1;
        int cnt=k-1;
        int n=nums.size();

        if(k==1) return true;

        while(j<n){
            if((nums[i]>nums[i-1]) && (nums[j]>nums[j-1])){
                cnt--;
                if(cnt==0) return true;
                i++;
                j++;
            }
            else{
                cnt=k-1;
                i++;
                j++;
            }
        }
        return false;
    }
};