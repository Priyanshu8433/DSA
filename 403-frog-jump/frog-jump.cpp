class Solution {
public:
    
    bool solve(int idx, vector<int> &stones, int last, vector<vector<int>> &dp, unordered_map<int,int> &mp){
        if(idx==stones.size()-1) return true;
        if(dp[idx][last]!=-1) return dp[idx][last];

        int delJump[]={-1,0,1};

        for(int i=0; i<3; i++){
            int nextJump=last+delJump[i];
            if(nextJump>0){
                int nextStone=stones[idx]+nextJump;
                if(mp.count(nextStone) && mp[nextStone]<=nextJump+idx){
                    if(solve(mp[nextStone],stones,nextJump,dp,mp)) return true;
                }
                //////////////////////
                // for(int j=1; j<=nextJump; j++){
                //     if(idx+j<stones.size() && stones[idx+j]==nextStone){
                //         if(solve(idx+j,stones,nextJump,dp)) return true;
                //     }
                // }
                //////////////////////
                // int low=idx+1,high=min(idx+nextJump,(int)stones.size()-1);

                // while(low<=high){
                //     int mid=low+(high-low)/2;
                //     cout<<idx<<" "<<last<<endl;
                //     if(stones[mid]==nextStone){
                //         if(solve(mid,stones,nextJump,dp)) return true;
                //     }
                //     else if(stones[mid]<nextStone){
                //         low=mid+1;
                //     }
                //     else{
                //         high=mid-1;
                //     }
                // }
            }
        }
        return dp[idx][last]=false;
    }

    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(stones.size(), vector<int>(stones.size()+1,-1));
        unordered_map<int,int> mp;
        for(int i=0; i<stones.size(); i++) mp[stones[i]]=i;
        return solve(0,stones,0,dp,mp);
    }
};