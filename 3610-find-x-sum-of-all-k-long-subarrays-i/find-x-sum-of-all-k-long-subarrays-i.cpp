class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i + k <= n; i++) {
             unordered_map<int,int> mp;

            for (int j = 0; j < k; j++) 
                mp[nums[i+j]]++;

            vector<pair<int,int>> vec(mp.begin(), mp.end());
            sort(vec.begin(), vec.end(), [](auto &a, auto &b){
                if (a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });

            int t = x;
            int currSum = 0;

            for (auto &p : vec) {
                currSum += p.first * p.second;
                t -=1;
                if (t == 0) break;
            }
            ans.push_back(currSum);
        }
        return ans;
    }
};
