class Solution {
public:
    bool solve(int d, vector<int>& position, int m){
        int last=-1;
        for(int x: position){
            if(last==-1 || x-last>=d){
                last=x;
                m--;
            }
            if(!m) break;
        }
        return m==0;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low=1;
        int high=position.back()-position[0];

        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(mid,position,m)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return high;
    }
};