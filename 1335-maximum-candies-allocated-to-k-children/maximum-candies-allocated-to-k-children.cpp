class Solution {
public:
    bool canGive(int candy, vector<int>& candies, long long k){
        int i=0;
        int n=candies.size();
        while(i<n){
            if(candies[i]>=candies[i]){
                long long kidsCanEat=min(1ll*candies[i]/candy,k);
                k-=kidsCanEat;
            }
            i++;
            if(k==0) return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1,high=*max_element(candies.begin(),candies.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canGive(mid,candies,k)){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};