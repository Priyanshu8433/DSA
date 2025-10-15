class Solution {
public:
    bool solve(int k, vector<int> &nums){
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

    int maxIncreasingSubarrays(vector<int>& nums) {
        int low=1,high=nums.size()/2;
        int maxi=0;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(solve(mid,nums)){
                maxi=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return maxi;
    }
};