class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n=len(nums)
        k=n
        curr=nums[-1]
        for i in range(n-2,-1,-1):
            if(nums[i]==nums[i+1]):
                nums.pop(i)
                k-=1
            else:
                curr=nums[i]
        return k