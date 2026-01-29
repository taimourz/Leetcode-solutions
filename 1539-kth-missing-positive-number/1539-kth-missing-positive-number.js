/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var findKthPositive = function(arr, k) {
    
    let i = 0
    while(i < arr.length)
    {
        let j = arr[i] - 1

        if(arr[i] != arr[j] && arr[i] <= arr.length)
        {
            [arr[i], arr[j]] = [arr[j],arr[i]]
        }
        else
        {
            i++
        }
    }

    let ans = []
    let extra_nums = new Set()
    for(let i = 0; i < arr.length; i++)
    {
        if(arr[i] != i+1)
        {
            ans.push(i+1)
            extra_nums.add(arr[i])
        }
    }

    let n = arr.length
    let j = 1
    debugger
    while(ans.length < k)
    {
        debugger
        let candidate_num = n + j
        if(!extra_nums.has(candidate_num))
        {
            ans.push(candidate_num)
        }
        j++
    }

    
    debugger
    return ans[k-1]
};


console.log(findKthPositive([2,3,4,7,11], 5))
console.log(findKthPositive([1,2,3,4],2))
