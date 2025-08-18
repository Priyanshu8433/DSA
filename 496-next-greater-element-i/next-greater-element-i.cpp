class Solution {
    int lSearch(int x, vector<int> &v){
        for(int i=0; i<v.size(); i++){
            if(v[i]==x) return i;
        }
        return -1;
    }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();

        vector<int> res(m);
        for(int i=0; i<m; i++){
            int x=nums1[i];
            int idx=lSearch(x,nums2);

            bool flag=false;

            for(int j=idx+1; j<n; j++){
                if(nums2[j]>x){
                    flag=true;
                    res[i]=nums2[j];
                    break;
                }
            }
            if(!flag) res[i]=-1;
        }
        return res;
    }
};