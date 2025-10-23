class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool onePresent=false;
        int n=nums.size();
        for(int &x: nums){
            if(x==1){
                onePresent=true;
            }
            else if(x<=0 || x>n) x=1;
        }
        for(int x: nums){
            cout<<x<<" ";
        }
        cout<<endl;

        if(!onePresent) return 1;

        for(int i=0; i<n; i++){
            int num=abs(nums[i]);
            int idx=num-1;
            nums[idx]=nums[idx]<0?nums[idx]:-1*nums[idx];
        }

        for(int x: nums){
            cout<<x<<" ";
        }

        for(int i=0; i<n; i++){
            if(nums[i]>0) return i+1;
        }
        return n+1;
    }
};