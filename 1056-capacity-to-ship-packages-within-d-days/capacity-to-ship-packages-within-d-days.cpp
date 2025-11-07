class Solution {
public:
    bool isPoss(int weight, vector<int>& weights, int days){
        int temp=weight;
        for(int x: weights){
            if(days<=0) return false;
            if(temp>=x){
                temp-=x;
            }
            else{
                days--;
                temp=weight;
                temp-=x;
                if(days<=0) return false;
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight=*max_element(weights.begin(), weights.end());
        int low=maxWeight;
        int n=weights.size();
        int high=((ceil((double)n/days)*maxWeight));
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPoss(mid,weights,days)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};