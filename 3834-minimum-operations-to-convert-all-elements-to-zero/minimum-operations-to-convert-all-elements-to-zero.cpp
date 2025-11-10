class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> s;
        int ops=0;
        for(int x: nums){
            while(!s.empty() && s.top()>x) s.pop();

            if(!x) continue;

            if(s.empty() || s.top()<x){
                s.push(x);
                ops++;
            }
        }
        return ops;
    }
};