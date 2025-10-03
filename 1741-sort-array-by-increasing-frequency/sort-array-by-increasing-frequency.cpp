class Solution {
public:
    typedef pair<int,int> P;

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int x: nums) mp[x]++;

        auto cmp=[](P &a, P &b){
            if(a.second==b.second) return a.first<b.first;
            return a.second>b.second;
        };

        priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);

        for(auto it: mp){
            pq.push({it.first,it.second});
        }

        vector<int> ans;

        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();

            ans.insert(ans.end(),temp.second,temp.first);
        }

        return ans;
    }
};