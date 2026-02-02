class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));

        for(int i=0; i<n; i++) dist[i][i]=0;

        for(auto vec: edges){
            int u=vec[0];
            int v=vec[1];
            int wt=vec[2];
            dist[u][v]=wt;
            dist[v][u]=wt;
        }

        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
                }
            }
        }

        vector<int> ans(n,0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                if(dist[i][j]<=distanceThreshold) ans[i]++;
            }
        }
        int maxi=INT_MAX;
        int currCity=-1;
        for(int i=0; i<n; i++){
            if(ans[i]<=maxi){
                maxi=ans[i];
                currCity=i;
            }
        }
        return currCity;
    }
};