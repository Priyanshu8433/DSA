class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int x: nums) mp[x]++;
        int n=nums.size()/2;
        for(auto itr: mp){
            if(itr.second==n) return itr.first;
        }
        return 0;
    }
};