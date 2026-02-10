class Solution {
public:
    int solve(vector<int> &arr){
        int n=arr.size();
        vector<int> nse(n);
        vector<int> pse(n);
        stack<int> s;
        for(int i=n-1; i>=0; i--){
            int curr=arr[i];
            while(!s.empty() && arr[s.top()]>=curr) s.pop();

            if(s.empty()) nse[i]=n;
            else nse[i]=s.top();
            s.push(i);
        }

        while(!s.empty()) s.pop();

        for(int i=0; i<n; i++){
            int curr=arr[i];
            while(!s.empty() && arr[s.top()]>curr) s.pop();

            if(s.empty()) pse[i]=-1;
            else pse[i]=s.top();
            s.push(i);
        }

        int maxArea=0;

        for(int i=0; i<n; i++){
            int breadth=nse[i]-pse[i]-1;
            int height=arr[i];

            maxArea=max(maxArea,breadth*height);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> temp(m,0);
        int maxArea=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1') temp[j]++;
                else temp[j]=0;
            }
            for(int x: temp) cout<<x<<" ";
            cout<<endl;
            maxArea=max(maxArea,solve(temp));
            cout<<maxArea<<endl;
        }
        return maxArea;
    }
};