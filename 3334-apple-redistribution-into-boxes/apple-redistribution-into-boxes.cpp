class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(),[](int &a, int &b){
            return a>b;
        });
        int total=accumulate(apple.begin(), apple.end(),0);
        int cnt=0;
        int i=0,j=0;
        int m=capacity.size();
        int n=apple.size();

        while(i<n){
            if(capacity[j]>=apple[i]){
                capacity[j]-=apple[i];
                i++;
            }
            else{
                apple[i]-=capacity[j];
                capacity[j]=0;
                j++;
            }
        }

        return j+1;
    }
};