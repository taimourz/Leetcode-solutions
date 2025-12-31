/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkInclusion = function(s1, s2) {
  const pattern_map = new Map()
  for(const c of s1) pattern_map.set(c, (pattern_map.get(c) || 0) + 1)
  
  const window_map = new Map()
  let windowStart = 0;

  for(let windowEnd = 0; windowEnd < s2.length; windowEnd++)
  {
    let leftChar = s2[windowEnd]
    window_map.set(leftChar, (window_map.get(leftChar) || 0) + 1)

    if(windowEnd - windowStart + 1 > s1.length)
    {
      let charStart = s2[windowStart]
      window_map.set(charStart, window_map.get(charStart) - 1)
      if(window_map.get(charStart) === 0) window_map.delete(charStart)
      windowStart++;
    }


    if(window_map.size === pattern_map.size)
    {
      let match = true
      for(const [key, val] of pattern_map)
      {
        if(window_map.get(key) !== val)
        {
          match = false;
          break;
        }
      }
      if(match) return true
    }
  }

  return false;
  
  
};
