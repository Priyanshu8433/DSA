class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<bool> &vis, vector<bool> &pathVis, unordered_set<int> &st, int last){
        vis[node]=true;
        pathVis[node]=true;

        bool flag=true;
        for(int x: graph[node]){
            if(!vis[x]){
                if(!dfs(x,graph,vis,pathVis,st,node)){
                    flag=false;
                    return false;
                }
            }
            else{
                if((pathVis[x]) || x==node){
                    flag=false;
                    return false;
                }
            }
        }
        pathVis[node]=false;
        if(flag=true) st.insert(node);
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n,false);
        vector<bool> pathVis(n,false);
        unordered_set<int> st;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathVis,st,-1);
            }
        }
        vector<int> ans(st.begin(),st.end());
        sort(ans.begin(),ans.end());
        return ans;
    }
};