class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        stack<int> stG;
        stack<int> stS;
        vector<int> nge(n);
        vector<int> nse(n);
        vector<int> pge(n);
        vector<int> pse(n);

        for(int i=n-1; i>=0; i--){
            int curr=nums[i];

            // next greater element
            while(!stG.empty() && nums[stG.top()]<=curr) stG.pop();

            if(stG.empty()) nge[i]=n;
            else nge[i]=stG.top();

            stG.push(i);

            // next smaller element
            while(!stS.empty() && nums[stS.top()]>=curr) stS.pop();

            if(stS.empty()) nse[i]=n;
            else nse[i]=stS.top();
            stS.push(i);
        }

        while(!stG.empty()) stG.pop();
        while(!stS.empty()) stS.pop();

        for(int i=0; i<n; i++){
            int curr=nums[i];

            // prev greater element
            while(!stG.empty() && nums[stG.top()]<curr) stG.pop();

            if(stG.empty()) pge[i]=-1;
            else pge[i]=stG.top();

            stG.push(i);

            // prev smaller element
            while(!stS.empty() && nums[stS.top()]>curr) stS.pop();

            if(stS.empty()) pse[i]=-1;
            else pse[i]=stS.top();
            stS.push(i);
        }


        long long sum=0;

        for(int i=0; i<n; i++){
            long long add=1ll*(nge[i]-i)*(i-pge[i])*nums[i];
            long long sub=1ll*(nse[i]-i)*(i-pse[i])*nums[i];

            sum+=(add-sub);
        }
        

        return sum;
    }
};