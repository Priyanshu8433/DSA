class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        reverse(nums.begin(), nums.end());
        vector<int> ans;
        ans.push_back(nums[0]);
        int n=nums.size();
        long long op=0;
        for(int i=1; i<n; i++){
            int prev=nums[i-1];
            int curr=nums[i];
            if(curr>prev){
                int parts=curr/prev;
                if(curr%prev!=0) parts++;
                op+=(parts-1);
                nums[i]=nums[i]/parts;
            }
        }
        return op;
    }
};