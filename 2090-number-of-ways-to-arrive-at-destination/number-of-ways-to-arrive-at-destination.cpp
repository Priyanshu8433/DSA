class Solution {
public:
    int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<long long>> dis(n,vector<long long>(2,0));
        for(auto &x: dis) x[0]=LONG_MAX;
        dis[0][0]=0;
        dis[0][1]=1;

        vector<vector<pair<int,long long>>> adjList(n);
        for(auto vec: roads){
            int u=vec[0];
            int v=vec[1];
            int time=vec[2];
            adjList[u].push_back({v,time});
            adjList[v].push_back({u,time});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});

        while(!pq.empty()){
            long long time=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto p: adjList[node]){
                int adjNode=p.first;
                long long addTime=p.second;
                if(0ll+time+addTime<dis[adjNode][0]){
                    dis[adjNode][0]=time+addTime;
                    dis[adjNode][1]=(dis[node][1])%MOD;
                    pq.push({time+addTime,adjNode});
                }
                else if(0ll+time+addTime==dis[adjNode][0]){
                    dis[adjNode][1]=(dis[adjNode][1]%MOD+dis[node][1]%MOD)%MOD;
                    // pq.push({time+addTime,adjNode});
                }
            }
        }

        return dis[n-1][1]%MOD;
    }
};