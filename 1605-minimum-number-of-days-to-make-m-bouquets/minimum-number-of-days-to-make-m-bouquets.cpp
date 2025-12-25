class Solution {
public:
    bool isPoss(int days, vector<int>& bloomDay, int m, int k){
        int temp=k;
        for(int d: bloomDay){
            if(d<=days) temp--;
            else temp=k;
            if(temp==0){
                m--;
                temp=k;
                if(m==0) break;
            }
        }

        return m==0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=1,high=*max_element(bloomDay.begin(), bloomDay.end());
        int ans=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPoss(mid,bloomDay,m,k)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};