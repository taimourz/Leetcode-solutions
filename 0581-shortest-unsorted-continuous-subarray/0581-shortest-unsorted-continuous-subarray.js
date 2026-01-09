/**
 * @param {number[]} nums
 * @return {number}
 */
var findUnsortedSubarray = function(nums) {
    if(nums.length==1) return 0
    
    let low = 0
    let high = nums.length - 1

    while(low<nums.length && nums[low] <= nums[low+1]) low++

    if(low==nums.length-1) return 0 // b/c already sorted

    while(high>=0 && nums[high] >= nums[high-1]) high--

    let maxElement = -Infinity
    let minElement = Infinity
    for(let i = low; i <= high; i++)
    {
        maxElement = Math.max(nums[i], maxElement)
        minElement = Math.min(nums[i], minElement)
    }
    debugger
    while(low>=0 && nums[low-1] > minElement) low--
    while(high<nums.length && nums[high+1] < maxElement) high++

    return high - low + 1
}


console.log(findUnsortedSubarray([2,6,4,8,10,9,15]))
console.log(findUnsortedSubarray( [1,2,3,4]))
console.log(findUnsortedSubarray([1]))

/*
aa


2,6,4,8,10,9,15
l             r




*/
