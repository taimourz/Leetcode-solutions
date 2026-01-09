/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var backspaceCompare = function(s, t) {

    ans = []

    let r = t.length - 1

    let str1 = ''
    let str2 = ''

    while(r>=0)
    {
        debugger
        if(t[r] != '#')
        {
            str2 += t[r]
            r--
        }else if(t[r] == '#')
        {
            let count = 0
            while(t[r]=='#')
            {
                count++
                r--
            }
            r -= count
        }
    }
    r = s.length - 1
    while(r>=0)
    {
        let count = 0
        if(s[r] != '#')
        {
            str1 += s[r]
            r--
        }else if(s[r] == '#')
        {
            let count = 0
            while(s[r]=='#')
            {
                count++
                r--
            }
            r -= count
        }
    }
    debugger

    return str1 == str2
    

    
};


console.log(backspaceCompare("ab#c","ad#c"))
console.log(backspaceCompare("ab##","c#d#"))
