/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
var findAnagrams = function(s, p) {
    
    let pattern_map = new Map()
    let ans = []
    for(let char of p)
    {
        pattern_map.set(char, (pattern_map.get(char) || 0) + 1)
    }
    
    let windowStart = 0
    let window_map = new Map()
    
    for(let windowEnd = 0; windowEnd < s.length; windowEnd++)
    {
        let rightChar = s[windowEnd]
        window_map.set(rightChar, (window_map.get(rightChar) || 0) + 1)
        
        
        if(windowEnd - windowStart + 1 > p.length)
        {
            let leftChar = s[windowStart]
            window_map.set(leftChar, window_map.get(leftChar) - 1)
            if(window_map.get(leftChar) === 0){
              window_map.delete(leftChar)
            }
            windowStart++; 
        }

        if(window_map.size === pattern_map.size)
        {
            debugger
            let match = true
            for(const [key, value] of pattern_map)
            {
               if(value != window_map.get(key)) 
               {
                match = false
                break;
               }
            }
            if(match) ans.push(windowStart)
        }
    }
    return ans
};

// console.log(findAnagrams("cbaebabacd", "abc"))