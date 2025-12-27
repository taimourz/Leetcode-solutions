/**
 * @param {number[]} fruits
 * @return {number}
 */
var totalFruit = function(fruits) {
    let windowStart = 0;
    let max_count = 0;

    const mp = new Map()

    for(let windowEnd = 0; windowEnd < fruits.length; windowEnd++)
    {
        mp.set(fruits[windowEnd], (mp.get(fruits[windowEnd]) || 0 ) + 1 )
        debugger
        if(mp.size > 2)
        {
            mp.set(fruits[windowStart], mp.get(fruits[windowStart]) - 1)
            while(mp.get(fruits[windowStart]) === 0)
            {
                mp.delete(fruits[windowStart])
            }
            windowStart++;     
            
        }
        max_count = Math.max(max_count, windowEnd - windowStart + 1)

    }

    return max_count;
    
};

// console.log(totalFruit([1,2,3,2,2]))

/*

- use a map to keep track of fruits we have picked. 
- shrink the window if map > 3. 
- remove the left most. decrease count
- somehow, we need to keep record of max fruits we have picked so far. 



[1 , 2 ,1]
     |  |


[0, 1, 2, 2]
    |     |
count 3
max_count 3


[1, 2, 3, 2, 2]
    |     |
map    
count 2

*/