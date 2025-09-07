class Solution {
public:
    vector<int> sumZero(int n) {
        int t=n/2;
        vector<int> ans;

        for(int i=(-1*t);i<0; i++){
            ans.push_back(i);
        }

        if(n%2!=0) ans.push_back(0);

        for(int i=1; i<=t; i++){
            ans.push_back(i);
        }

        return ans;
    }
};