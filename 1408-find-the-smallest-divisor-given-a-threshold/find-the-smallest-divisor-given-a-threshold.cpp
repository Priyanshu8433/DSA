class Solution {
public:
    bool solve(int div, vector<int>& nums, int threshold){
        long long sum=0;
        for(int x: nums){
            sum+=ceil((double)x/div);
            if(sum>threshold) return false;
        }
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(mid,nums,threshold)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};