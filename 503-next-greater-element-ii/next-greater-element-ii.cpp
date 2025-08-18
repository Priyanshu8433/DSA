class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n=nums.size();

        for(int i=n-1; i>=0; i--){
            int x=nums[i];
            while(!s.empty() && s.top()<=x){
                s.pop();
            }
            s.push(x);
        }

        for(int i=n-1; i>=0; i--){
            int x=nums[i];
            while(!s.empty() && s.top()<=x){
                s.pop();
            }

            if(s.empty()) nums[i]=-1;
            else nums[i]=s.top();
            s.push(x);
        }

        return nums;
    }
};