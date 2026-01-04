/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let nextNonDuplicate = 1

    debugger
    for(let r = 1; r < nums.length; r++)
    {
        if(nums[nextNonDuplicate - 1] != nums[r])
        {
            nums[nextNonDuplicate] = nums[r]
            nextNonDuplicate++
        }
    }

    return nextNonDuplicate 
    
};

// console.log(removeDuplicates([1,1,2]))
// console.log(removeDuplicates([0,0,1,1,1,2,2,3,3,4]))


/*


    r
0,0,1,1,1,2,2,3,3,4
l

0 1 0



*/
