class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int prev=0;
        int cnt=0;
        for(int x: target){
            if(x>prev){
                cnt+=(x-prev);
            }
            prev=x;
        }
        return cnt;
    }
};