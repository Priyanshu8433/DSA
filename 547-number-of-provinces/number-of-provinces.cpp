class Solution {
public:
    void bfs(int node, vector<vector<int>> &adjList, vector<int> &vis){
        queue<int> q;
        q.push(node);
        vis[node]=1;

        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int c: adjList[x]){
                if(!vis[c]) q.push(c);
                vis[c]=1;
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adjList(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                if(isConnected[i][j]==1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int> vis(n,0);
        int cnt=0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                cnt++;
                bfs(i,adjList,vis);
            }
        }
        return cnt;
    }
};