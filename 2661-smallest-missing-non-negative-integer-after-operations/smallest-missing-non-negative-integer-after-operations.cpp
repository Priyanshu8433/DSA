class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> mp;

        for(int i=0; i<value; i++) mp[i]=0;

        // store the count of all the modulo value
        for(auto num: nums){
            if(num>0)
                mp[num%value]++;
            else{
                int mod=value-(abs(num)%value);
                mp[mod%value]++;
            }
        }

        int mini=INT_MAX;
        int key=INT_MAX;

        // find the minimum module count
        for(auto it: mp){
            mini=min(mini,it.second);
        }

        // find the minimum key with the minimum modulo count
        for(auto it: mp){
            if(mini==it.second){
                key=min(key,it.first);
            }
        }

        return value*mini+key;
    }
};