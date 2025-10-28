class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int left=0;
        int right=0;
        int n=nums.size();

        for(int x: nums) right+=x;
        int cnt=0;
        for(int x: nums){
            if(x==0){
                if(left==right){
                    cnt+=2;
                }
                else if(abs(left-right)==1) cnt+=1;
            }
            else{
                left+=x;
                right-=x;
            }
        }
        return cnt;
    }
};