class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();

        for(int &x: nums) x*=-1;
        for(int &x: nums) cout<<x<<" ";


        for(int i=0; i<n; i++){
            int idx=abs(nums[i])-1;
            if(nums[idx]>0){
                nums[idx]*=-1;
                return idx+1;
            }
            nums[idx]*=-1;
        }

        return -1;
    }
};