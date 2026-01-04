/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    let nextElement = 0

    for(let r = 0; r < nums.length; r++)
    {
        debugger
        if(nums[r] !== val)
        {
            nums[nextElement] = nums[r]
            nextElement++
        }
    }

    return nextElement 

};

console.log(removeElement([3,2,2,3],3))
console.log(removeElement([0,1,2,2,3,0,4,2],2))


/*

3,j2,2,3
  r
 


*/
