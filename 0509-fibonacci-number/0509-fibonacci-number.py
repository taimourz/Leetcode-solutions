class Solution:
    def fib(self, n: int) -> int:
        # base case
        dp = [-1] * (n+1)
        def helper(n):
            if n <= 0:
                return 0
            if n <= 2:
                return 1
            if dp[n] != -1:
                return dp[n]

            dp[n] = self.fib(n-2) + self.fib(n-1)

            return dp[n]

        return helper(n)



"""

fib(2) = fib(1) + fib(0)

fib(1) = 


"""