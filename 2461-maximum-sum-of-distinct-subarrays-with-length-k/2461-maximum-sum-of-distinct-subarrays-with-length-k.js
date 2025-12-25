/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumSubarraySum = function(nums, k) {
    let max_sum = 0;
    let window_sum = 0;
    let window_start = 0;

    let window = new Map();

    for(let window_end = 0; window_end < nums.length; window_end++)
    {
        window_sum += nums[window_end]
        window.set(nums[window_end], ((window.get(nums[window_end]) || 0) + 1))

        if(window_end >= k - 1)
        {
            if(window.size=== k)
            {
                max_sum = Math.max(max_sum, window_sum)
            }

            window_sum -= nums[window_start]
            window.set(nums[window_start], window.get(nums[window_start]) - 1)

            if(window.get(nums[window_start]) === 0)            
            {
                window.delete(nums[window_start]);
            }

            window_start++;
        }



    }
    return max_sum;

};






/*

- declare max_sum windowSum and windowStart to keep track.
- create a hash Map called window. 
- windowEnd will help us iterate, normal iteration so far. 
- keep track of Sum
- use .set method to set the value of current element.get from map, if not then set to 0 + 1
- Then check if we have reached the window size. remember arrays are zero indexed. 
- update max_sum only and only if all distinct
- Then it is time to move the window. therefore remove the first element in window from current sum
- make sure to do the same for the map. 
- if the value for removed element becomes zero, remove it from the map.
- start moves.







[1,5,4,2,9,9,9] k = 3

i = 0
    j = i+3


i
1,5,4



*/
