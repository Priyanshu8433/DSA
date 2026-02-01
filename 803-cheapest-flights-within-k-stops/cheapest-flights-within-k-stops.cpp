class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> minCost(n,INT_MAX);
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,src}});
        minCost[src]=0;

        vector<vector<pair<int,int>>> adjList(n);
        for(auto vec: flights){
            int from=vec[0];
            int to=vec[1];
            int price=vec[2];

            adjList[from].push_back({to,price});
        }

        while(!pq.empty()){
            int stops=pq.top().first;
            int cost=pq.top().second.first;
            int city=pq.top().second.second;
            pq.pop();

            for(auto it: adjList[city]){
                int nextCity=it.first;
                int price=it.second;
                if((stops+1<=k || nextCity==dst) && cost+price<minCost[nextCity]){
                    minCost[nextCity]=cost+price;
                    pq.push({stops+1,{minCost[nextCity],nextCity}});
                }
            }
        }

        return minCost[dst]==INT_MAX?-1:minCost[dst];
    }
};