/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {

    let windowStart = 0
    const mp = new Map()
    let max_substr = 0

    for(let windowEnd = 0; windowEnd < s.length; windowEnd++)
    {
        mp.set(s[windowEnd], (mp.get(s[windowEnd]) || 0) + 1)
        debugger

        while(mp.get(s[windowEnd]) > 1)
        {
            mp.set(s[windowStart], mp.get(s[windowStart]) - 1)

            if(mp.get(s[windowStart === 0]))
            {
                mp.delete(s[windowStart])
            }

            windowStart++;

        }

        max_substr = Math.max(max_substr, windowEnd - windowStart + 1)
    }

    return max_substr;
};

// console.log(lengthOfLongestSubstring("abcabcbb"))
