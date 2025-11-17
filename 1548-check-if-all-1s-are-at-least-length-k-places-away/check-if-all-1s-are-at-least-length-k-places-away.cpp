class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        bool flag=true;
        int t=k;
        for(int x: nums){
            if(t<=0) flag=true;
            if(x==1){
                if(!flag) return false;
                flag=false;
                t=k;
            }
            else{
                t--;
            }
        }
        return true;
    }
};