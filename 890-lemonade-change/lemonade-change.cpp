class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mp={{5,0},{10,0},{20,0}};

        for(int x: bills){
            int change=x-5;
            // 10 ke
            int pay10=min(change/10,mp[10]);
            change-=(10*pay10);
            mp[10]-=pay10;
            // 5 ke
            int pay5=min(change/5,mp[5]);
            change-=(5*pay5);
            mp[5]-=pay5;

            if(change!=0) return false;
            mp[x]++;
        }

        return true;
    }
};