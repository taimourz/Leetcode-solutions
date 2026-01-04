/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    nums.sort((a,b) => a-b)
    let ans = []
    for(let i = 0; i < nums.length; i++)
    {
        let l = i + 1
        let r = nums.length - 1
        
        if(i>0 && nums[i] === nums[i-1]) continue


        debugger
        while(l < r)
        {
            let curr_sum = nums[i] + nums[l] + nums[r]
            if(curr_sum === 0)
            {
                ans.push([nums[i], nums[l], nums[r]])
                l++
                r--
                while(l < r && nums[l] === nums[l-1]) l++
                while(l < r && nums[r] === nums[r+1]) r--
            }
            else if(curr_sum < 0)
            {
                l++
            }
            else
            {
                r--
            }
        }
    }
    return ans;

    
};


console.log(threeSum([-1,0,1,2,-1,-4]))
console.log(threeSum([-2,0,1,1,2]))


/*

             k
-1,0,1,2,-1,-4

-4 -1 -1 0 1 2 

*/

