class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.length();
        vector<int> arr(n,0);
        int cnt=0;
        for(int i=n-1; i>=0; i--){
            if(customers[i]=='Y') cnt++;
            arr[i]=cnt;
        }
        int minPen=INT_MAX;
        int minHour=0;
        cnt=0;
        for(int i=0; i<n; i++){
            int penalty=arr[i]+cnt;
            if(penalty<minPen){
                minPen=penalty;
                minHour=i;
            }
            if(customers[i]=='N') cnt++;
        }
        if(cnt<minPen) return n;
        return minHour;
    }
};