/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function(n) {
    
    let seen = new Set() 
    while(n!=0)
    {
        debugger
        let sum = find_sum(n)
        if(seen.has(sum)) return false
        else if(sum==1) return true
        else 
        {
            seen.add(sum)
            n=sum
        }
        
    }

    function find_sum(n)
    {

        let sum = 0
        while(n!=0)
        {
            let last_digit = n % 10
            n = Math.trunc(n/10)
            sum += last_digit * last_digit
        }
        return sum

    }
};


console.log(isHappy(19))
console.log(isHappy(2))
