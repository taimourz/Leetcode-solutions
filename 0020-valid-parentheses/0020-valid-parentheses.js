/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    if(s.length < 2) return false;
    stk = []

for(let i = 0; i < s.length; i++)
{
  debugger
  if(stk.length == 0 || s[i] == '(' || s[i] == '{' || s[i] == '[')
  {
    stk.push(s[i])
  }else{
    let elem = stk[stk.length - 1]
    if( (elem == '(' && s[i] == ')') ||  (elem == '{' && s[i] == '}') || (elem == '[' && s[i] == ']') ){
      stk.pop()
    }else{
        return false;
    }
  }

}

    if(stk.length == 0) return true;
    else return false;

}


/*

()[]{}


(
[)
]



(
]

)








*/