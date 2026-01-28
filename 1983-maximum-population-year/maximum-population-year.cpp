class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int arr[101]={0};
        for(auto vec: logs){
            arr[vec[0]-1950]++;
            arr[vec[1]-1950]--;
        }
        int sum=0;
        int maxi=0;
        int maxYear=0;
        for(int i=0; i<100; i++){
            sum+=arr[i];
            arr[i]=sum;
            if(arr[i]>maxi){
                maxi=arr[i];
                maxYear=i+1950;
            }
        }
        return maxYear;
    }
};