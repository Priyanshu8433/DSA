class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int left=0,right=0;
        int n=nums.size();
        long long cnt=0;
        int nonZero=0;

        while(right<n){
            if(nums[left]!=0 && nums[right]!=0){
                left++;
                right++;
            }
            else if(nums[left]==0 && nums[right]==0){
                cnt+=(right-left+1);
                right++;
            }
            else if(nums[left]==0 && nums[right]!=0){
                left=right;
            }
        }
        return cnt;
    }
};