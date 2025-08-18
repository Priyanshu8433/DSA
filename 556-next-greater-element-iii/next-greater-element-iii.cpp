class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> num;
        int temp=n;

        while(n!=0){
            int rem=n%10;
            n/=10;
            num.push_back(rem);
        }
        reverse(num.begin(), num.end());
        next_permutation(num.begin(),num.end());
        int s=num.size();

        for(int i=0; i<s; i++){
            
            if(INT_MAX/10<n || INT_MAX-num[i]<n*10) return -1;
            n=(n*10+num[i]);
        }

        if(n<=temp) return -1;
        return n;
    }
};