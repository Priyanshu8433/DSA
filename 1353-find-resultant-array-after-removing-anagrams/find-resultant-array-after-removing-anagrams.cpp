class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {

        int n=words.size();
        vector<string> res;
        for(int i=n-1; i>0; i--){
            string curr=words[i];
            sort(curr.begin(), curr.end());
            string prev=words[i-1];
            sort(prev.begin(), prev.end());
            if(curr==prev){
                words.erase(words.begin()+i);
            }
        }
        return words;
    }
};