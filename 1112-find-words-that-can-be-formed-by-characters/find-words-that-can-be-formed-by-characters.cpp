class Solution {
public:
    bool isGood(string word, unordered_map<char,int> &mp){
        unordered_map<char,int> pp;

        for(char ch: word) pp[ch]++;

        for(auto it: pp){
            if(mp.find(it.first)==mp.end() || it.second>mp[it.first]) return false;
        }
        return true;
    }

    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> mp;
        for(char ch: chars) mp[ch]++;
        int cnt=0;

        for(string word: words){
            if(isGood(word,mp)) cnt+=word.length();
        }
        return cnt;
    }
};