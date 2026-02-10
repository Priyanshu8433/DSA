class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n=heights.size();
        vector<int> pse(n);
        vector<int> nse(n);

        // prev smaller height
        for(int i=0; i<n; i++){
            int curr=heights[i];
            while(!s.empty() && heights[s.top()]>=curr) s.pop();

            if(s.empty()) pse[i]=-1;
            else pse[i]=s.top();

            s.push(i);
        }
        while(!s.empty()) s.pop();
        // next smaller height
        for(int i=n-1; i>=0; i--){
            int curr=heights[i];

            while(!s.empty() && heights[s.top()]>curr) s.pop();

            if(s.empty()) nse[i]=n;
            else nse[i]=s.top();

            s.push(i);
        }

        int maxArea=0;

        for(int i=0; i<n; i++){
            int height=heights[i];
            int breadth=nse[i]-pse[i]-1;

            maxArea=max(maxArea,height*breadth);
        }

        return maxArea;
    }
};