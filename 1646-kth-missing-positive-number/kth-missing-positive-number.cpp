class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> st(arr.begin(),arr.end());
        for(int i=1; i<=2001; i++){
            if(!st.count(i)) k--;
            if(!k) return i;
        }
        return -1;
    }
};