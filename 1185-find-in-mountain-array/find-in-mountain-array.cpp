/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &m) {
        int low=1,high=m.length()-1; 

        while(low<=high){
            int mid=low+(high-low)/2;
            int curr=m.get(mid);
            int prev=m.get(mid-1);
            if(prev<curr){
                // peak is on the right
                low=mid+1;
            }
            else{
                // peak is on the left
                high=mid-1;
            }
        }
        // high is the peak index
        int peak=high;
        cout<<peak;

        // search on the left half
        low=0,high=peak;
        while(low<=high){
            int mid=low+(high-low)/2;
            int curr=m.get(mid);
            if(curr==target) return mid;
            if(curr>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        // search on the right half
        low=peak+1,high=m.length()-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            int curr=m.get(mid);
            if(curr==target) return mid;
            if(curr>target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return -1;
    }
};