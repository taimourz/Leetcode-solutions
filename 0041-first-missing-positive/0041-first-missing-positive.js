/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
   
    let i = 0
    while(i < nums.length)
    {
        let j = nums[i] - 1

        if(nums[i] > 0 && nums[i] <= nums.length && nums[i] != nums[j])
        {
            [nums[i], nums[j]] = [nums[j], nums[i]]
        }
        else
        {
            i++
        }
    }

    debugger

    for(let i = 0; i < nums.length; i++)
    {
        debugger
        if(nums[i] != i+1)
        {
            return i+1
        }
    }

    return nums.length + 1
};


console.log(firstMissingPositive([1,2,0]))
console.log(firstMissingPositive([3,4,-1,1]))
console.log(firstMissingPositive([7,8,9,11,12]))
console.log(firstMissingPositive([-3, 1, 5, 4, 2]))
console.log(firstMissingPositive([3, -2, 0, 1, 2]))
console.log(firstMissingPositive([3, 2, 5, 1]))


