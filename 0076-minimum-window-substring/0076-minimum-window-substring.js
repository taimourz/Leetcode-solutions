var minWindow = function(s, t) {
    let pattern_map = new Map()
    for(let char of t)
    {
        pattern_map.set(char, (pattern_map.get(char) || 0) + 1)
    }
    let all_elems_present = false
    let windowStart = 0
    let minLength = s.length + 1
    let substrStart = 0    
    let window_map = new Map()
    for(let windowEnd = 0; windowEnd < s.length; windowEnd++)
    {
        let rightChar = s[windowEnd]
        window_map.set(rightChar, (window_map.get(rightChar) || 0) + 1)
        all_elems_present = true
        for(const [key, value] of pattern_map)
        {
            if((window_map.get(key) || 0) < value)
            {
                all_elems_present = false
                break;
            }
        }
        while(all_elems_present)
        {
            if(windowEnd - windowStart + 1 < minLength)
            {
                minLength = windowEnd - windowStart + 1
                substrStart = windowStart
            }
            let leftChar = s[windowStart]
            window_map.set(leftChar, window_map.get(leftChar) - 1)
            if(window_map.get(leftChar) === 0)
            {
                window_map.delete(leftChar)
            }
            windowStart++
            all_elems_present = true
            for(const [key, value] of pattern_map)
            {
                if((window_map.get(key) || 0) < value) 
                {
                    all_elems_present = false
                    break;
                }
            }
        }
    }
    return minLength > s.length ? "" : s.substring(substrStart, substrStart + minLength) 
};

console.log(minWindow("ADOBECODEBANC", "ABC"))


/*

- keep track of pattern freq
- move the window

ABC

{
    A : 1
    B : 1
    C : 1

}

A D O B E C O D E B A N C
|     
          |




*/
