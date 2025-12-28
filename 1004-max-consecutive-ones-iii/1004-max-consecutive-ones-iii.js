/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var longestOnes = function(nums, k) {
    let windowStart = 0;
    let mp = {}
    let maxWinLen = 0

    for(let windowEnd = 0; windowEnd < nums.length; windowEnd++)
    {
        let rightChar = nums[windowEnd]
        if(!(rightChar in mp))
        {
            mp[rightChar] = 0

        }
        mp[rightChar] += 1

        while(mp[0] > k)
        {
            let leftChar = nums[windowStart]
            mp[leftChar] -= 1
            windowStart++;
        }

         maxWinLen = Math.max(maxWinLen, windowEnd - windowStart + 1)

    }

    return maxWinLen;
};


// console.log(longestOnes([1,1,1,0,0,0,1,1,1,1,0], 2))

/*



 nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3

[0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1]
 |
 |

flag = is_one        


Freq 
    {
        0 : 2,
        1 : 2 
    }

max_win = 4





 */