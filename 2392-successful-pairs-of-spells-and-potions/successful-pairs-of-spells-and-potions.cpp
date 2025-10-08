class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n=spells.size();
        int m=potions.size();
        vector<int> res(n);
        for(int i=0; i<n; i++){
            long long val=ceil((double)success/spells[i]);
            auto it=lower_bound(potions.begin(), potions.end(), val);
            if(it==potions.end()){
                res[i]=0;
            }
            else{
                int idx=it-potions.begin();
                res[i]=m-idx;
            }
        }
        return res;
    }
};