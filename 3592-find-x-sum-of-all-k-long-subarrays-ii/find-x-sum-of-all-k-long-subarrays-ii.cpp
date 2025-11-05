class Solution {
public:
    void insertPair(pair<int,int> p, set<pair<int,int>> &topx,set<pair<int,int>> &st, long long &sum, int x){
        if(topx.size()<x || p>*topx.begin()){
            sum+=1ll*p.first*p.second;
            topx.insert(p);

            if(topx.size()>x){
                auto smallest=*topx.begin();
                sum-=1ll*smallest.first*smallest.second;
                topx.erase(smallest);
                st.insert(smallest);
            }
        }
        else st.insert(p);
    }

    void removePair(pair<int,int> p, set<pair<int,int>> &topx,set<pair<int,int>> &st, long long &sum, int x){
        if(topx.find(p)!=topx.end()){
            sum-=1ll*p.first*p.second;
            topx.erase(p);
            if(!st.empty()){
                auto largest=*st.rbegin();
                st.erase(largest);
                topx.insert(largest);
                sum+=1ll*largest.first*largest.second;
            }
        }
        else st.erase(p);
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        int i=0,j=0;
        unordered_map<int,int> mp;
        set<pair<int,int>> topx;
        set<pair<int,int>> st;
        vector<long long> ans;
        long long sum=0;

        while(j<n){
            if(mp[nums[j]]){
                removePair({mp[nums[j]],nums[j]},topx,st,sum,x);
            }
            mp[nums[j]]++;
            insertPair({mp[nums[j]],nums[j]},topx,st,sum,x);

            if(j-i+1==k){
                ans.push_back(sum);

                removePair({mp[nums[i]],nums[i]},topx,st,sum,x);
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                else insertPair({mp[nums[i]],nums[i]},topx,st,sum,x);
                i++;
            }
            j++;
        }

        return ans;
    }
};