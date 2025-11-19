class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return helper(n,dp);
    }

    int helper(int n, vector<int>& dp){
        // base case
        if(n == 0) return 0;
        if(n == 1) return 1;

        if(dp[n] != -1) return dp[n];

        // recursive relation
        return dp[n] = fib(n-1) + fib(n-2);
    }
};

/*
fib(2)
fib(1) + fib(0)
1 + 1

*/