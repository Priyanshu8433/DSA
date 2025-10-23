class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st;
        for(int x: banned){
            if(x<=n) st.insert(x);
        }

        int length=0;
        int sum=0;
        for(int i=1; i<=n; i++){
            if(i+sum<=maxSum){
                if(st.count(i)==0){
                    length++;
                    sum+=i;
                }
            }
            else break;            
        }
        return length;
    }
};