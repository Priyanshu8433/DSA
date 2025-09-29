class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> s;
        int n=speed.size();
        vector<pair<int,int>> arr;
        for(int i=0; i<n; i++){
            arr.push_back({position[i],speed[i]});
        }
        sort(arr.begin(),arr.end(),[](pair<int,int> &a, pair<int,int> &b){
            return a.first>b.first;
        });

        for(int i=0; i<n; i++){
            double time=((double)(target-arr[i].first)/arr[i].second);
            if(s.empty() || time>s.top()){
                s.push(time);
            }
            else if(time<=s.top()) continue;
        }

        return s.size();
    }
};