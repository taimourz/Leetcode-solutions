/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function(nums) {
    
    let i = 0
    while(i < nums.length)
    {
        debugger
        if(nums[i] != i+1)
        {
            let j = nums[i] - 1 
            if(nums[i] != nums[j]) 
            {
                [nums[i], nums[j]] = [nums[j], nums[i]]
            }
            else
            {
                return nums[i]
            }
        }
        else
        {
            i++
        }
    }

    return 0

};


console.log(findDuplicate([1,3,4,2,2]))
console.log(findDuplicate([3,1,3,4,2]))
console.log(findDuplicate( [3,3,3,3,3]))
