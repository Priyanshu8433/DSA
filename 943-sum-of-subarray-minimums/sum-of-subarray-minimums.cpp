class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD=1e9+7;
        int n=arr.size();
        vector<int> nse(n);
        vector<int> pse(n);
        stack<int> s;
        for(int i=0; i<n; i++){
            if(s.empty()){
                pse[i]=-1;
            }
            else{
                while(!s.empty() && arr[s.top()]>=arr[i]) s.pop();
                if(s.empty()) pse[i]=-1;
                else pse[i]=s.top();
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();

        for(int i=n-1; i>=0; i--){
            if(s.empty()){
                nse[i]=n;
            }
            else{
                while(!s.empty() && arr[s.top()]>arr[i]) s.pop();
                if(s.empty()) nse[i]=n;
                else nse[i]=s.top();
            }
            s.push(i);
        }

        int sum=0;

        for(int i=0; i<n; i++){
            int subArr=((nse[i]-i)%MOD*(i-pse[i])%MOD)%MOD;
            sum=sum%MOD+(1LL*subArr%MOD*arr[i]%MOD)%MOD;
        }
        return sum;
    }
};