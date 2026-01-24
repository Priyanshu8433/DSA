class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);

        if(st.count(endWord)==0) return 0;

        while(!q.empty()){
            string word=q.front().first;
            int num=q.front().second;
            q.pop();
            int n=word.length();

            if(word==endWord) return num;

            for(int i=0; i<n; i++){
                char ch=word[i];
                for(char x='a'; x<='z'; x++){
                    word[i]=x;
                    if(st.count(word)){
                        q.push({word,num+1});
                        st.erase(word);
                    }
                }
                word[i]=ch;
            }
        }

        return 0;
    }
};