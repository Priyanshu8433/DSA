class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int> arr(n,0);
        for(auto vec: shifts){
            if(vec[2]==0){
                arr[vec[0]]--;
                if(vec[1]+1<n)
                    arr[vec[1]+1]++;
            }
            else{
                arr[vec[0]]++;
                if(vec[1]+1<n)
                    arr[vec[1]+1]--;
            }
        }
        for(int i=1; i<n; i++){
            arr[i]+=arr[i-1];
        }

        for (int i = 0; i < n; i++) {
            int shift = arr[i] % 26;
            s[i] = char('a' + (s[i] - 'a' + shift + 26) % 26);
        }


        return s;
    }
};