class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int first=-1,second=-1;
        for(int i=1; i<n; i++){
            if(nums[i]==nums[i-1]){
                if(first==-1) first=nums[i];
                else{
                    second=nums[i];
                    break;
                }
            }
        }
        return {first,second};
    }
};