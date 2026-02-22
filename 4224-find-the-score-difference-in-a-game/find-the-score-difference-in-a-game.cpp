class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int player[2]={0};
        int active=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==1) active=!active;
            if((i+1)%6==0) active=!active;
            player[active]+=nums[i];
        }

        return player[0]-player[1];
    }
};