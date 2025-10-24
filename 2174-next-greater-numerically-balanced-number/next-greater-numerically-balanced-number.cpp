class Solution {
public:
    bool isBalanced(int num){
        vector<int> freq(10,0);

        while(num){
            int rem=num%10;
            num/=10;
            freq[rem]++;
        }

        for(int i=0; i<10; i++){
            if(freq[i]!=0 && freq[i]!=i) return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int i=n+1; i<=1224444; i++){
            if(isBalanced(i)) return i;
        }
        return 0;
    }
};