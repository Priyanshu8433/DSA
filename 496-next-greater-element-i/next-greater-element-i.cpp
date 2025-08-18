class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        unordered_map<int,int> mp;
        for(int i=0; i<m; i++){
            mp[nums1[i]]=i;
        }
        stack<int> s;
        vector<int> res(m);

        for(int i=n-1; i>=0; i--){
            int x=nums2[i];
            if(mp.find(x)!=mp.end()){
                while(!s.empty() && s.top()<x){
                    s.pop();
                }

                if(s.empty()){
                    nums1[mp[x]]=-1;
                }
                else{
                    nums1[mp[x]]=s.top();
                }
            }
            s.push(nums2[i]);
        }

        return nums1;
    }
};