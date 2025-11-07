class Solution {
public:
    bool isPoss(long long power,vector<long long> &diff, int r, int k){
        int n=diff.size();
        vector<long long> temp=diff;
        long long currSum=0;
        for(int i=0; i<n; i++){
            currSum+=temp[i];
            if(currSum<power){
                long long required=power-currSum;
                if(k<required) return false;

                k-=required;
                currSum+=required;
                if(i+2*r+1<n) temp[i+2*r+1]-=required;
            }
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n=stations.size();
        vector<long long> diff(n,0);

        for(int i=0; i<n; i++){
            diff[max(0,i-r)]+=stations[i];
            if(i+r+1<n) diff[i+r+1]-=stations[i];
        }

        long long low=*min_element(stations.begin(),stations.end());
        long long high=accumulate(stations.begin(),stations.end(),0LL)+k;
        long long ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(isPoss(mid,diff,r,k)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};