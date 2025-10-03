class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int, vector<int>> pq;
        // for(int x: nums) pq.push(x);
        // k--;
        // while(k--){
        //     pq.pop();
        // }
        // return pq.top();

        make_heap(nums.begin(), nums.end());

        k--;
        while(k--){
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }

        return nums[0];
    }
};