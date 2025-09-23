#define MOD 1000000007

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        // Next smaller element
        vector<int> nse(n);
        stack<int> s;
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && arr[s.top()]>arr[i]) s.pop();

            if(s.empty()) nse[i]=n;
            else nse[i]=s.top();

            s.push(i);
        }

        while(!s.empty()) s.pop();

        //Previous smaller element
        vector<int> pse(n);
        for(int i=0; i<n; i++){
            while(!s.empty() && arr[s.top()]>=arr[i]) s.pop();

            if(s.empty()) pse[i]=-1;
            else pse[i]=s.top();

            s.push(i);
        }

        //count the number of subarrays
        long long total=0;
        for(int i=0; i<n; i++){
            int right=nse[i]-i;
            int left=i-pse[i];
            total=(total+(left*right*1ll*arr[i])%(int)MOD)%(int)MOD;
        }
        return total;
    }
};