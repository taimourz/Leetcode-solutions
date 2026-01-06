/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    
    let diff = Infinity
    let minDiff = Infinity
    let sum = 0

    nums.sort((a,b) => a-b)
    for(let i = 0; i < nums.length; i++)
    {
        
        let l = i+1
        let r = nums.length - 1

        if(i > 0 && nums[i] == nums[i-1]) continue;


        while(l<r)
        {
            if(nums[i] == -1 && nums[l] == 1 && nums[r] == 2) debugger
            let curr_sum = nums[i] + nums[l] + nums[r]
            let curr_diff     = Math.abs(curr_sum - target)
            
            if(curr_diff < minDiff)
            {
                minDiff = curr_diff
                sum = nums[i] + nums[l] + nums[r]
            }

            if(curr_sum < target)
            {
                l++
            }
            else if(curr_sum > target)
            {
                r--
            }else
            {
                return sum
            }


        }

    }
    return sum
    
}

console.log(threeSumClosest([-1,2,1,-4],1))
console.log(threeSumClosest([0,0,0],1))







