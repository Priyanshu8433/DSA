class Solution {
    public long minimalKSum(int[] nums, int k) {
        Arrays.sort(nums);
    long sum = 0;
    long current = 1;
    
    for (int i = 0; i < nums.length && k > 0; i++) {
        // Skip duplicates
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        // Count of numbers we can take before nums[i]
        long count = Math.min(k, Math.max(0, (long)nums[i] - current));
        
        // Sum of arithmetic series: (first + last) * count / 2
        sum += (current + current + count - 1) * count / 2;
        k -= count;
        
        // Next start number after nums[i]
        current = (long)nums[i] + 1;
    }
    
    // If k still remains, continue after last number
    if (k > 0) {
        sum += (current + current + k - 1) * k / 2;
    }
    
    return sum;
    }
}