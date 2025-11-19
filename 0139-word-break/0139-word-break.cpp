class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && wordSet.count(s.substr(j, i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};


/*

create unordered_set. to find easily. unordered b/c order does not matter.
make a dp array that is going to store our answers. Initially all false except first and last true
two loops. every time we will check a portion of string (substring)
if found in our set, then that means one entry in dp is going to be true. (idk why)
if we are doing with the string and we found a word then it means true. (yes word bank can create a word like that.)


leetcode

i=1
j=0

l

i=2
j=1

l
le

i=3
j=0

l

i=3
j=1

le

i=3
j=2

lee


i=4
j=0

leet

i=4
j=1

eet



*/