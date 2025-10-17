class Solution {
public:
    bool isVowel(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> counts(n); //prefix array to store the count of vowel strings
        int cnt=0;

        for(int i=0; i<n; i++){
            if(isVowel(words[i].front()) && isVowel(words[i].back())) cnt++;
            counts[i]=cnt;
        }

        vector<int> ans; // Resultant array

        for(auto vec: queries){
            if(vec[0]==0){
                ans.push_back(counts[vec[1]]);
            }
            else{
                ans.push_back(counts[vec[1]]-counts[vec[0]-1]);
            }
        }

        return ans;
    }
};