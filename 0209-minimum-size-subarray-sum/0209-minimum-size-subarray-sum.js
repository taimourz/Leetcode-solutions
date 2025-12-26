/**
 * @param {number} target
 * @param {number[]} nums
 * @return {number}
 */
var minSubArrayLen = function(target, nums) {

  let windowStart = 0;
  let windowSum   = 0;
  let smallestWin = Infinity; // 3

  // [2, 1, 5, 2, 3, 2], S=7    
  //  |     |
  for(let windowEnd = 0; windowEnd < nums.length; windowEnd++)
  {
    windowSum += nums[windowEnd] // 8

    while(windowSum >= target)
    {
        smallestWin = Math.min(windowEnd - windowStart + 1, smallestWin)
        windowSum -= nums[windowStart]
        windowStart++;
    }


  }

  return  smallestWin === Infinity ? 0 : smallestWin;;


};




/*

 nums = [2,3,1,2,4,3]

 window size should be adjusted dynamically. 

  0. 1. 2. 3. 4. 5    
 [2, 1, 5, 2, 3, 2], S=7    
        |        |  

2 - 0 + 1 = 3
2 - 1 + 1 = 2
5 - 2 + 1 = 4




[2, 1, 5, 2, 3, 2], S=  






*/






