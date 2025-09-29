class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int n=asteroids.size();

        for(int i=0; i<n; i++){
            int curr=asteroids[i];

            if(curr>0){
                // curr is positive, i.e., moving upwards
                s.push(curr);
            }
            else{
                // curr is negative, i.e., moving downwards
                while(!s.empty() && s.top()>0){
                    if(abs(curr)>s.top()) s.pop();
                    else break;
                }
                if(s.empty() || s.top()<0){
                    s.push(curr);
                }
                else if(abs(curr)==s.top()) s.pop();
            }
        }

        vector<int> res;
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(),res.end());

        return res;
    }
};