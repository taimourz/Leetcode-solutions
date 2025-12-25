/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countSubarrays = function(nums, k) {
   let l = 0;
   
   let subarray_sum = 0
   let count = 0

   for(let r = 0; r<nums.length; r++)
   {
        subarray_sum += nums[r]

        while(subarray_sum * (r-l+1) >= k)
        {
            subarray_sum -= nums[l]
            l++;
        }

        count += (r-l+1)

   }
   return count;
};