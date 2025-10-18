class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_set<int> st;

        for(int num: nums){
            int low=num-k;
            int high=num+k;
            int valid=num;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(!st.count(mid)){
                    valid=mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            st.insert(valid);
        }
        return st.size();
    }
};