class Solution {
public:
    void bfs(int node, vector<vector<int>> &adjList, vector<bool> &vis, unordered_map<int,int> &mp, unordered_map<int,set<int>> &st, const int &currSet){
        queue<int> q;
        q.push(node);
        vis[node]=true;
        mp[node]=currSet;
        st[currSet].insert(node);

        while(!q.empty()){
            int currNode=q.front();
            q.pop();
            for(int x: adjList[currNode]){
                if(!vis[x]){
                    q.push(x);
                    vis[x]=true;
                    mp[x]=currSet;
                    st[currSet].insert(x);
                }
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int,int> mp;
        unordered_map<int,set<int>> st;

        vector<bool> vis(c+1,false);
        vector<vector<int>> adjList(c+1);
        for(auto vec: connections){
            adjList[vec[0]].push_back(vec[1]);
            adjList[vec[1]].push_back(vec[0]);
        }
        int currSet=1;

        for(int i=1; i<=c; i++){
           if(!vis[i]){
                bfs(i,adjList,vis,mp,st,currSet);
                currSet++;
           }
        }

        vector<int> ans;

        for(auto query: queries){
            int node=query[1];
            int setNum=mp[node];
            if(query[0]==1){
                // maintainance check
                if(st[setNum].count(node)){
                    ans.push_back(node);
                }
                else{
                    if(st[setNum].empty()) ans.push_back(-1);
                    else ans.push_back(*st[setNum].begin());
                }
            }
            else{
                // deactivate the node
                st[setNum].erase(node);
            }
        }
        return ans;
    }
};