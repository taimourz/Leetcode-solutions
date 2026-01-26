/**
 * @param {string} s
 * @return {number}
 */
var countGoodSubstrings = function(s) {
    
    let window_start = 0
    
    let mp = new Map()
    let count = 0

    for(let window_end = 0; window_end < s.length; window_end++)
    {
        mp.set(s[window_end], ((mp.get(s[window_end]) || 0) + 1))
        if(window_end >= 2)
        {
            debugger
            let is_unique = true
            mp.forEach((val, idx) => {
                if(val > 1)
                {
                    is_unique = false
                }
            });
            if(is_unique) count++

            mp.set(s[window_start], mp.get(s[window_start]) - 1)

            if(mp.get(s[window_start]) === 0)
            {
                mp.delete(s[window_start])
            }
            window_start++
            

        }
        
    }

    return count
};


console.log(countGoodSubstrings("xyzzaz"))
console.log(countGoodSubstrings("aababcabc"))
