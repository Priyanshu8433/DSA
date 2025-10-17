class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for(string s: strs){
            string curr=s;
            sort(curr.begin(),curr.end());
            mp[curr].push_back(s);
        }
        vector<vector<string>> res;

        for(auto it: mp) res.push_back(it.second);
        return res;
    }
};