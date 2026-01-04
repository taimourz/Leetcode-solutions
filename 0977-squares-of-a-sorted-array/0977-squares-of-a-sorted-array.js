/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortedSquares = function(nums) {
    let ans = []
    nums.forEach((n) => {
        ans.push(n*n)
    })
    ans.sort((a,b) => a-b)
    return ans;
};

// console.log(sortedSquares([-4,-1,0,3,10]))
