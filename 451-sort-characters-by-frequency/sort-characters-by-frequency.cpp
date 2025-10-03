class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto ch: s) mp[ch]++;

        auto cmp = [](pair<char,int> &a, pair<char,int> &b){
            return a.second<b.second;
        };

        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(cmp)> pq(cmp);

        for(auto it: mp){
            pq.push({it.first, it.second});
        }

        string res="";

        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();

            res+=string(p.second,p.first);
        }

        return res;
    }
};