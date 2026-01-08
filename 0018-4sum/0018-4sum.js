/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function(nums, target) {
    nums.sort((a,b) => a-b)

    let ans = new Set()
    for(let i = 0; i < nums.length; i++)
    {
        if(i>0 && nums[i-1] == nums[i]) continue

        for(j = i+1; j < nums.length; j++)
        {
            let l = j+1
            let r = nums.length - 1
            
            if(j>i+1 && nums[j-1] == nums[j]) continue

            while(l<r)
            {
                let curr_sum = nums[i] + nums[j] + nums[l] + nums[r]

                if(curr_sum==target)
                {
                    ans.add([nums[i], nums[j], nums[l], nums[r]])
                    l++
                    r--
                    while(l<r && nums[l] == nums[l-1]) l++
                    while(l<r && nums[r] == nums[r+1]) r--
                }
                else if(curr_sum<target)
                {
                    l++
                }
                else
                {
                    r--
                }
            }
        }
    }

    let arr = [...ans]
    return arr
    
};


console.log(fourSum([1,0,-1,0,-2,2],0))
console.log(fourSum([2,2,2,2,2],8))





