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

        int maxi=INT_MAX;
        int key=INT_MAX;

        // find the minimum module count
        for(auto it: mp){
            maxi=min(maxi,it.second);
        }

        // find the minimum key with the minimum modulo count
        for(auto it: mp){
            if(maxi==it.second){
                key=min(key,it.first);
            }
        }


        return value*maxi+key;
    }
};